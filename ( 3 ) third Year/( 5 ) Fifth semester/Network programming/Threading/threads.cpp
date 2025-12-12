#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <functional>
#include <queue>


class ThreadPool{

public:
    ThreadPool(unsigned int threads_cound){
        for(int i=0;i<threads_cound){
            thread_pool.push_back();
        }
    }

private:
    std::vector<std::thread> thread_pool;

    std::mutex mutex;
    std::queue<std::function<void()>> tasks;
};