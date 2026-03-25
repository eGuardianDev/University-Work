#include <iostream>



int Iterative_GCD(int a,int b){
    while( a != 0 && b != 0){
        if(a > b){
            a -=b;
        }else{
            b -= a;
        }
    }
    return std::max(a,b);
}

int Recursive_GCD(int a, int b){
    if(a <=0 || b <=0)
    {
        return std::max(a,b);
    }
    if(a >b){
        return Recursive_GCD(a%b, b);
    }else{
        return Recursive_GCD(a, b%a);
    }
}


int main(){

    int a =-5;
    int b =10;
    std::cout << Iterative_GCD(a,b) << std::endl;
    std::cout << Recursive_GCD(a,b) << std::endl;


    return 0;
}