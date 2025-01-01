#include "heap.hpp"
#include "kheap.hpp"
#include <iostream>


int main(){

    kHeap h(3);

    h.insert(40);
    h.insert(15);

    std::cout << h.extractMin() << "\n";
    std::cout << h.returnCap() << "\n";
    int* data = h.getHeap();


    for(int i =0;i<h.Size();++i){
        std::cout << data[i] <<  " ";
    }


    return 0;
}