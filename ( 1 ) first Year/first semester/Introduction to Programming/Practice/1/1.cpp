#include <iostream>

int main(){

    int k;
    std::cin >> k;


    int sum = 1;

    // normal way
    // for(int i= 0; i<k;++i){
    //     sum *=2;
    // }

    //binary way
    sum = sum << k;

    std::cout << sum << std::endl;


    return 0;
}