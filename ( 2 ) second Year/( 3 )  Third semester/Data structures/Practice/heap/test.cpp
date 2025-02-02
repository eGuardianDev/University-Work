#include "heap.hpp"
#include <iostream>


int main(){

    MinHeap heap;

    // heap.Add(3);
    // heap.Add(2);
    // heap.Add(15);
    // heap.Add(0);
    // heap.Add(5); 

    // std::cout << heap.Remove(3) << std::endl;
    // // std::cout << "size: " <<heap.Size() << std::endl;

    // while(heap.Size()){
    //     std::cout << heap.Extract() << std::endl;
    // }

    std::vector<int> a = {3,10,8,2,14};

    heap.buildFromVector(a);
    while(heap.Size()){
        std::cout << heap.Extract() << std::endl;
    }

  
    return 0;
}