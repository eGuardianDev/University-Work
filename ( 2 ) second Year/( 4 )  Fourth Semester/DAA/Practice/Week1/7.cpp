#include <iostream>
#include <cmath>

const int maxx = 10000;
long a[maxx];
int main(){


    int n =0 ;
    std::cin >> n;

    int i =0;
    for(i =0;i<n;++i){
        std::cin >> a[i];
    }

    // int sum = 0;
    // int count = 1;
    
    // while(count <= n){
    //     long x = ceil((float)n / count);
    //     for(i =0;i<x;++i){
    //         for(int j = 0;j<=count;++j){
    //             sum += data[j];
    //         }
    //     }
    //     count +=2;
    // } ?? doesn't work


    int sum = 0;
    int tempsum =0;
    for(int k =1;k<=n;k+=2){
        tempsum = 0;
        for(int i=1;i<k;++i) tempsum +=a[i];
        sum += tempsum;
        for(int i =k;i<n-k+1;++i){
            tempsum -= a[i - 1];
            tempsum += a[i + k - 1];
            sum += tempsum;
        }
    }

    std::cout << sum;

    


    return 0;
}