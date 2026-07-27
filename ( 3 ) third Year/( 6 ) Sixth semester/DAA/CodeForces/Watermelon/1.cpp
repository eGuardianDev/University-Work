#include <iostream>


int main(){
    int num;
    std::cin >> num;

    if(num % 2 ==0 && num > 2){
        std::cout << "YES" <<std::endl;
    }else{
        std::cout << "NO" <<std::endl;
    }
    return 0;
}