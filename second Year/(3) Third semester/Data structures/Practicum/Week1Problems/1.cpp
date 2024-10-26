#include <iostream>




long long pow(long long x, unsigned long long n ){
    if(n ==0) return 1;

    return x * pow(x,--n);
}

long long fastPow(long long x, unsigned long long n ){
    if(n ==0) return 1;
    if(n%2 == 1){
        return fastPow(x*x,n/2);
    }
    return x*fastPow(x*x, n/2);
}


int main(){
    long long x = 0;
    unsigned long long n = 0;
    std::cout << "x: "; std::cin >> x;
    std::cout << "pow: "; std::cin >> n;
    
    std::cout << pow(x,n);
    std::cout << fastPow(x,n);

    return 0;
}