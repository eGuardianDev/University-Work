#include <iostream>
#include <thread>
#include <vector>

void worker(int id) {
    std::cout << "Thread " << id << " started\n";
}

int main() {
    std::vector<std::thread> threads;

    for (int i = 0; i < 20; i++)
        threads.emplace_back(worker, i);

    // join all
    for (auto& t : threads)
        t.join();

    std::cout << "All threads finished\n";
}

