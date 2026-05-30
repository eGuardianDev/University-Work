
// 1 buffer


#ifndef LOGIC_HPP
#define LOGIC_HPP


#include "Threads.hpp"
#include "entities.hpp"
#include "properties.hpp"
#include "random_numbers.hpp"
#include <atomic>
#include <iostream>
#include <mutex>
#include <set>
#include <vector>
#include <fstream>


#include <cassert>


class Logic{
    
    std::ofstream record_file_;
    int step_ = 1;
    float total_time_ = 0.0f;

    public:

    float averageTime(){
        return total_time_/step_;
    }



    Logic(std::vector<std::vector<Entities>> &map,
            number_generator & rng,
        int threads_count = Config::World::THREADS)
            :rng_(rng),
            border_mutexes_(threads_count),
            is_bordered_(map.size(),-1),
            count_using_threads_(threads_count)
        {
        // size
        // std::vector<Entities>(map[0].size());
        
        // files
        if constexpr (Config::Debug::RECORD_TO_FILE) {
            record_file_.open("simulation.csv");
            record_file_ << "step,fish,sharks\n";
        }


        int threads = count_using_threads_;

        int grid_height = Config::World::GRID_SIZE_HEIGHT;

        assert(grid_height % threads == 0 && "Grid height must be divisible by number of threads");
        int sector_height = grid_height/threads;
        sector_height_ = sector_height;
        
        // std::cout << threads << " " << grid_height << " " << sector_height << std::endl;

        int current = 0;
        for(int i = 0; i < threads; ++i) {
            int end = current + sector_height;

            sectors_.push_back({current,end-1});

            borders_.insert(current);
            borders_.insert(end-1);

            // first border
            int prev = (current - 1 + grid_height) % grid_height;
            int prev2 = (current - 2 + grid_height) % grid_height;
            is_bordered_[prev2]   = i-1;
            is_bordered_[prev]    = i-1;
            is_bordered_[current] = i-1;
            is_bordered_[current+1] = i-1;

            // second border
            int next = (end % grid_height);
            is_bordered_[end-2]  = i;
            is_bordered_[end-1]  = i;
            is_bordered_[next]   = i;
            is_bordered_[next+1] = i;

            int seed_t =rng.next_int(0, 100000);
            
            workers_.push_back(std::make_unique<ThreadWorker>(
                seed_t, sectors_[i], border_mutexes_, is_bordered_
            ));
            // std::cout << "Created new worker > id: " << i << " sectors [ " << current << " : " << end-1 << " ]" << std::endl; 


            current = end;
        }

        // for(int i =0;i<is_bordered_.size();++i){
        //     if(is_bordered_[i] != -1){
        //         std::cout << i << " " << is_bordered_[i] << std::endl;
        //     }
        // }


    }
    void spawnInitial(std::vector<std::vector<Entities>> &map) {
        for(int r = 0; r < map.size(); r++) {
            for(int c = 0; c < map[0].size(); c++) {
                int roll = rng_.next_int(0, 100);

                if(roll < Config::Spawn::INITIAL_FISH_DENSITY * 100) {
                    map[r][c].type = 1;
                    map[r][c].breading_timer = Config::Fish::STARTING_BREED_TIMER;
                }
                else if(roll < (Config::Spawn::INITIAL_FISH_DENSITY + Config::Spawn::INITIAL_SHARK_DENSITY) * 100) {
                    map[r][c].type = 2;
                    map[r][c].energy = Config::Shark::STARTING_ENERGY;
                }
            }
        }
    }

    void Step(std::vector<std::vector<Entities>>& map) {
        fishes_ = 0;
        sharks_ = 0;

            auto start = std::chrono::high_resolution_clock::now();
       
        for(int i = 0; i < workers_.size(); i++) {
           workers_[i]->dispatch([&, i](int start, int end, number_generator& rng) {
            
            int total_threads = count_using_threads_;
            int top_mutex_idx = (i - 1 + total_threads) % total_threads;
            int bottom_mutex_idx = i;

            int local_fishes = 0;
            int local_sharks = 0;

            // alternative sweep
            bool sweep_down = (step_ % 2 == 0);
            int r_start = sweep_down ? start : end;
            int r_end   = sweep_down ? end : start;
            int r_dir   = sweep_down ? 1 : -1;

            // horizontal sweep ever 2 steps
            bool sweep_right = (step_ % 4 < 2);
            int c_start = sweep_right ? 0 : Config::World::GRID_SIZE_WIDTH - 1;
            int c_end   = sweep_right ? Config::World::GRID_SIZE_WIDTH - 1 : 0;
            int c_dir   = sweep_right ? 1 : -1;

            for(int r = r_start; r != r_end + r_dir; r += r_dir) {
                
                bool lock_top = (r == start || r == start + 1);
                bool lock_bottom = (r == end || r == end - 1);

                std::unique_lock<std::mutex> lk_top, lk_bottom;
                if(lock_top) lk_top = std::unique_lock<std::mutex>(border_mutexes_[top_mutex_idx]);
                if(lock_bottom) lk_bottom = std::unique_lock<std::mutex>(border_mutexes_[bottom_mutex_idx]);

                for(int c = c_start; c != c_end + c_dir; c += c_dir) {
                    if(map[r][c].type == 1) {
                        local_fishes++; 
                        moveFish(map, r, c, rng); 
                    }
                    if(map[r][c].type == 2) {
                        local_sharks++; 
                        moveShark(map, r, c, rng); 
                    }
                }
            } 
            
            fishes_ += local_fishes;
            sharks_ += local_sharks;
        });
        }
        for(auto& w : workers_)
            w->wait();


        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> elapsed = end - start;
        
        if constexpr (Config::Debug::COUNT_ANIMALS) {
            std::cout << "Stats: \n"
                << " Step: "   << step_   << '\n'
                << " Fishes: " << fishes_ << '\n'
                << " Sharks: " << sharks_ << '\n'
                << " elapsed: " << elapsed.count() << '\n'
                << std::endl;
        }
        if constexpr (Config::Debug::RECORD_TO_FILE) {
            record_file_ << step_ << ',' << fishes_ << ',' << sharks_ << '\n';
        }
        total_time_ += elapsed.count();
        ++step_;
    }
    void Solo_Step(std::vector<std::vector<Entities>> &map) {
        
        for(int r = 0; r < map.size(); r++){
            for(int c = 0; c < map[0].size(); c++) {
                if(map[r][c].type == 1) // move fish
                {
                    fishes_ += 1;
                    moveFish(map, r, c,rng_);
                }
                if(map[r][c].type == 2) // move shark   
                {
                    sharks_+=1;
                    moveShark(map, r, c,rng_);
                }
            }   
        }


        if constexpr (Config::Debug::COUNT_ANIMALS) {
            std::cout << "Stats: \n" 
            << " Step: " << step_ << '\n'
            << " Fishes: " << fishes_ << '\n'
            << " Sharks: " << sharks_ << '\n'
            << std::endl;
        }
        if constexpr (Config::Debug::RECORD_TO_FILE) {
            record_file_ << step_ << ',' << fishes_ << ',' << sharks_ << '\n';
        }
        ++step_;

    }
    private:
    struct Neighbors {
        std::pair<int,int> cells[4];
        int count = 0;

        void add(int r, int c) { cells[count++] = {r, c}; }
    };

    Neighbors getNeighbors(std::vector<std::vector<Entities>> &map, int r, int c, int type = 0) {
        Neighbors result;
        int rows = Config::World::GRID_SIZE_HEIGHT;
        int cols = Config::World::GRID_SIZE_WIDTH;

        int up    = (r - 1 + rows) % rows;
        int down  = (r + 1) % rows;
        int left  = (c - 1 + cols) % cols;
        int right = (c + 1) % cols;

        if(map[up][c].type    == type) result.add(up, c);
        if(map[down][c].type  == type) result.add(down, c);
        if(map[r][left].type  == type) result.add(r, left);
        if(map[r][right].type == type) result.add(r, right);

        return result;
    }

    void thread_moveFish(std::vector<std::vector<Entities>> &map, int r, int c, number_generator& t_rng) {
        int idx = is_bordered_[r];
        if(idx != -1) {
            std::scoped_lock lk(border_mutexes_[idx]);
            moveFish(map, r, c, t_rng);
        } else {
            moveFish(map, r, c, t_rng);
        }
    }
    void thread_moveShark(std::vector<std::vector<Entities>>& map, int r, int c, number_generator& t_rng) {
        int idx = is_bordered_[r];
        if(idx != -1) {
            std::scoped_lock lk(border_mutexes_[idx]);
            moveShark(map, r, c, t_rng);
        } else {
            moveShark(map, r, c, t_rng);
        }
    }


    void moveFish(std::vector<std::vector<Entities>> &map, int r, int c, number_generator& t_rng) {
       
        if(map[r][c].moved == (step_ % 2)){
            return;
        } 

        Neighbors empty = getNeighbors(map, r, c, 0);

        Neighbors free;
        for(int i = 0; i < empty.count; i++) {
            auto [nr, nc] = empty.cells[i];
            if(!is_busy(map, nr, nc))
                free.add(nr, nc);
        }


        if(free.count == 0) {
            map[r][c] = map[r][c]; 
            map[r][c].moved = ((step_)%2);
            return;
        }

        auto [nr, nc] = free.cells[t_rng.next_int(0, free.count - 1)];

        map[nr][nc] = map[r][c];
        map[r][c].type = 0;    
        map[nr][nc].breading_timer--;
        map[nr][nc].moved = ((step_)%2);

        if(map[nr][nc].breading_timer <= 0) {
            map[r][c].type = 1;
            map[r][c].breading_timer = Config::Fish::STARTING_BREED_TIMER;
            map[nr][nc].breading_timer = Config::Fish::STARTING_BREED_TIMER;
            map[r][c].moved = ((step_)%2);
        }
    }
    void moveShark(std::vector<std::vector<Entities>> &map, int r, int c, number_generator& t_rng) {
        
        if(map[r][c].moved == (step_ % 2)){
            return;
        } 

        map[r][c].energy -= Config::Shark::STEP_LOSE_ENERGY;

        // die if no energy
        if(map[r][c].energy <= 0) {
            map[r][c].type = 0;
            return;  // just return
        }

        Neighbors fish = getNeighbors(map, r, c, 1);

        if(fish.count > 0) {
            auto [nr, nc] = fish.cells[t_rng.next_int(0, fish.count - 1)];
            map[nr][nc] = map[r][c];
            map[r][c].type = 0;
            map[nr][nc].energy += Config::Shark::EATING_GAIN_ENERGY;
            map[nr][nc].moved = ((step_)%2);
            
            // breed
            if(map[nr][nc].energy >= Config::Shark::BREED_ENERGY_REQUIRED) {
                map[r][c].type = 2;
                map[r][c].energy = Config::Shark::STARTING_ENERGY;
                map[nr][nc].energy = Config::Shark::STARTING_ENERGY;
                map[r][c].moved = ((step_)%2);

            }
            return;
        }

        // no fish
        Neighbors free;
        Neighbors candidates = getNeighbors(map, r, c, 0);
        for(int i = 0; i < candidates.count; i++) {
            auto [nr, nc] = candidates.cells[i];
            if(!is_busy(map, nr, nc))
                free.add(nr, nc);
        }

        if(free.count == 0) {
            map[r][c] = map[r][c];  // stays
            map[r][c].moved = ((step_)%2);
            return;
        }

        auto [nr, nc] = free.cells[t_rng.next_int(0, free.count - 1)];
        map[nr][nc] = map[r][c];
        map[nr][nc].moved = ((step_)%2);
        map[r][c].type = 0;

    }

    bool is_busy(
        std::vector<std::vector<Entities>> &map,
        int r,
        int c) {
        if(r < 0 || r >= Config::World::GRID_SIZE_HEIGHT 
        || c< 0 || c >= Config::World::GRID_SIZE_WIDTH){
            return true;
        }
        
        if(map[r][c].type != 0){
            return true;
        }

        return false;
    }




    bool isBorder(int r){
        return is_bordered_[r];
    }

    int getBorderMutexIndex(int r) {

        return is_bordered_[r];
        // if(r == 0 || r == 1) return sectors_.size()-1;
        // return (r-2) / sector_height_;
    }

    number_generator &rng_;
    // std::vector<ThreadWorker> workers_;
    std::vector<std::unique_ptr<ThreadWorker>> workers_;
    std::vector<std::pair<int,int>> sectors_;

    std::vector<int> is_bordered_;
    std::vector<std::mutex> border_mutexes_;

    std::set<int> borders_;

    int count_using_threads_ =0 ;
    int sector_height_ = 0;

    std::atomic<int> fishes_{0};
    std::atomic<int> sharks_{0};
};




#endif // LOGIC_HPP