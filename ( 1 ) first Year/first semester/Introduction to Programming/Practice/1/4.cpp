#include <iostream>


int GetLastN(unsigned a, unsigned n){

    unsigned int result = 0;  // 0000

    // unsigned a = 1110
    
    // mask is used to select bits
    // most of the time used with "&"
    unsigned int mask = 1; // 0001
    for(int i =0;i<n;++i){
        //find bit
        int lefover = a & mask;
        //save it 
        result |= lefover;
        //move mask one left
        //ready for next step
        mask = mask << 1;
    }
    return result;
}


int main(){

    int a = 0;
    std::cout << "Number with hidden meaning: ";
    std::cin >> a;


    int n = 0;
    std::cout << "Get last n bits - ";
    std::cin >> n;

    std::cout << "Result: " << GetLastN(a,n) << "\n";

    return 0;
}