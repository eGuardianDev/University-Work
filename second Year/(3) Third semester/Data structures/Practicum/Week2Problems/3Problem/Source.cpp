#include <bitset>
#include <cassert>
#include <iostream>


int main(){

    const unsigned int Max_N = 1024;
    std::bitset<Max_N> bitset;
    int n =0;
    std::cin >> n;
    
    assert(n<= Max_N);
    int a;
    for(int  i=0;i<n;i++){
        
        std:: cin >>a;
         bitset[a] = 1;
    }
    
    std::cout <<  bitset.count();

    return 0;
}