#include <iostream>
#include <cmath>

const int maxx = 10000;
long long  a[maxx];
int main(){


    int n =0 ;
    std::cin >> n;

    int i =0;
    for(i =0;i<n;++i){
        std::cin >> a[i];
    }
  
    //linear
    long long sum =0;
    for(int i =0;i<n;++i){
        sum += a[i] * (( (i+1) * (n-i) + 1)/2);
    }

    std::cout << sum;

    


    return 0;
}