#include <iostream>
#include "Vector.h"

int main(){
    Vector vec;
    // std::cout << vec.capacity;
    // std::cout << vec.GetSize();
    vec.append(1);
    vec.append(1);
    for(int i : vec){
        std::cout << i << " ";
    }
    // std::cout << vec.GetSize();
    return 0;
}