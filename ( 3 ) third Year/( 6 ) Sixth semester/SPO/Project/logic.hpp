#ifndef LOGIC_HPP
#define LOGIC_HPP


#include "entities.hpp"
#include "properties.hpp"
#include "random_numbers.hpp"
#include <iostream>
#include <vector>
#include <fstream>

class Logic{
    std::vector<std::vector<Entities>> n_map;
    
    std::ofstream record_file_;
    int step_ = 0;
    
    public:
    Logic(std::vector<std::vector<Entities>> &map,
         number_generator & rng)
         :rng_(rng){
        
        // size
        n_map.assign(map.size(),
        std::vector<Entities>(map[0].size()));
        
        // files
        if constexpr (Config::Debug::RECORD_TO_FILE) {
            record_file_.open("simulation.csv");
            record_file_ << "step,fish,sharks\n";
        }

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
    void Step(std::vector<std::vector<Entities>> &map) {
        clear_map();

        fishes_ = 0;
        sharks_ = 0;
        for(int r = 0; r < map.size(); r++){
            for(int c = 0; c < map[0].size(); c++) {
                if(map[r][c].type == 1) // move fish
                {
                    fishes_ += 1;
                    // n_map[r][c].type = 1;
                    moveFish(map, r, c);
                }
                if(map[r][c].type == 2) // move shark   
                {
                    sharks_+=1;
                    // n_map[r][c].type = 2;
                    moveShark(map, r, c);
                }
            }   
        }

        std::swap(map, n_map);
        if constexpr (Config::Debug::COUNT_ANIMALS) {
            std::cout << "Stats: \n" 
            << "Step: " << step_ << '\n'
            << "Fishes: " << fishes_ << '\n'
            << "Sharks: " << sharks_ << '\n'
            << std::endl;;
        }
        if constexpr (Config::Debug::RECORD_TO_FILE) {
            record_file_ << step_++ << ',' << fishes_ << ',' << sharks_ << '\n';
        }
        
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
    void moveFish(std::vector<std::vector<Entities>> &map, int r, int c) {
        Neighbors empty = getNeighbors(map, r, c, 0);

        Neighbors free;
        for(int i = 0; i < empty.count; i++) {
            auto [nr, nc] = empty.cells[i];
            if(!is_busy(map, n_map, nr, nc))
                free.add(nr, nc);
        }


        if(free.count == 0) {
            n_map[r][c] = map[r][c]; 
            return;
        }

        auto [nr, nc] = free.cells[rng_.next_int(0, free.count - 1)];

        n_map[nr][nc] = map[r][c];
        n_map[nr][nc].breading_timer--;

        if(n_map[nr][nc].breading_timer <= 0) {
            n_map[r][c].type = 1;
            n_map[r][c].breading_timer = Config::Fish::STARTING_BREED_TIMER;
            n_map[nr][nc].breading_timer = Config::Fish::STARTING_BREED_TIMER;
        }
    }
    void moveShark(std::vector<std::vector<Entities>> &map, int r, int c) {
        map[r][c].energy -= Config::Shark::STEP_LOSE_ENERGY;

        // die if no energy
        if(map[r][c].energy <= 0) {
            return;  // just return
        }

        Neighbors fish = getNeighbors(map, r, c, 1);

        if(fish.count > 0) {
            auto [nr, nc] = fish.cells[rng_.next_int(0, fish.count - 1)];
            n_map[nr][nc] = map[r][c];
            n_map[nr][nc].energy += Config::Shark::EATING_GAIN_ENERGY;
            
            map[nr][nc].type = 0;
            
            // breed
            if(n_map[nr][nc].energy >= Config::Shark::BREED_ENERGY_REQUIRED) {
                n_map[r][c].type = 2;
                n_map[r][c].energy = Config::Shark::STARTING_ENERGY;
                n_map[nr][nc].energy = Config::Shark::STARTING_ENERGY;
            }
            return;
        }

        // no fish
        Neighbors free;
        Neighbors candidates = getNeighbors(map, r, c, 0);
        for(int i = 0; i < candidates.count; i++) {
            auto [nr, nc] = candidates.cells[i];
            if(!is_busy(map, n_map, nr, nc))
                free.add(nr, nc);
        }

        if(free.count == 0) {
            n_map[r][c] = map[r][c];  // stays
            return;
        }

        auto [nr, nc] = free.cells[rng_.next_int(0, free.count - 1)];
        n_map[nr][nc] = map[r][c];

    }

    bool is_busy(
        std::vector<std::vector<Entities>> &map,
        std::vector<std::vector<Entities>> &n_map,
        int r, int c){
        if(r < 0 || r >= Config::World::GRID_SIZE_HEIGHT 
        || c< 0 || c >= Config::World::GRID_SIZE_WIDTH){
            return true;
        }
        
        if(map[r][c].type != 0 || n_map[r][c].type != 0){
            return true;
        }

        return false;
    }

    void clear_map(){
        for(auto& row : n_map)
            for(auto& cell : row)
                cell = Entities{};
    }

    int fishes_;
    int sharks_;
    number_generator &rng_;
};




#endif // LOGIC_HPP