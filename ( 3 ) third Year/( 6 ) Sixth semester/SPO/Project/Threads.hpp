#ifndef THREADS_HPP
#define THREADS_HPP

#include "random_numbers.hpp"
#include <condition_variable>
#include <functional>
#include <mutex>
#include <thread>
#include <utility>
#include <vector>


class ThreadWorker{

public:
    ThreadWorker(
        int seed, 
        std::pair<int,int> region,
        std::vector<std::mutex> &border_mutexes,
        std::vector<int> &mutex_mapping
        ): rng_(seed), region_(region),
        //  border_mutexes_(border_mutexes), 
         mutex_mapping_(mutex_mapping)
    {
        thread_ = std::thread(&ThreadWorker::loop, this);
    }

    ~ThreadWorker() {
        {
            std::unique_lock lk(wakeup_mutex_);
            alive_ = false;
        }
        cv_start_.notify_one();
        thread_.join();
    }

    // delete copy, allow nothing — mutex and thread are not copyable
    ThreadWorker(const ThreadWorker&) = delete;
    ThreadWorker& operator=(const ThreadWorker&) = delete;

    void dispatch(std::function<void(int, int, number_generator&)> work) {
        {
            std::unique_lock lk(wakeup_mutex_);
            // cv_done_.wait(lk, [this]{ return !ready_ && !done_ || true; });
            cv_done_.wait(lk, [this]{ return !ready_; }); 
            work_  = work;
            ready_ = true;
            done_  = false;  
        }
        cv_start_.notify_one();
    }

    void wait() {
        std::unique_lock lk(wakeup_mutex_);
        cv_done_.wait(lk, [this]{ return done_; });
        done_ = false;
    }

private:


    void loop() {
        while(true) {
            std::unique_lock lk(wakeup_mutex_);
            cv_start_.wait(lk, [this]{ return ready_ || !alive_; });

            if(!alive_) return;

            ready_ = false;
            lk.unlock();

            // do the work
            work_(region_.first, region_.second, rng_);

            {
                std::unique_lock lk2(wakeup_mutex_);
                done_ = true;
            }
            cv_done_.notify_one();
        }
    }


    number_generator rng_;
    std::pair<int,int> region_;
    // std::vector<std::mutex>& border_mutexes_;
    std::vector<int>& mutex_mapping_; 

    std::thread thread_;
    std::mutex wakeup_mutex_;

    std::condition_variable cv_start_;
    std::condition_variable cv_done_;

    std::function<void(int, int, number_generator&)> work_;

    bool ready_ = false;
    bool done_  = false;
    bool alive_ = true;
};



#endif // THREADS_HPP