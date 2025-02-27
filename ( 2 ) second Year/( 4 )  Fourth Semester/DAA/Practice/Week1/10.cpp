#include <cassert>
#include <climits>
#include <iostream>

long long const maxx = 100;
long long a[maxx];

int n = 0;
int minIndex(int start){
    assert(start <= n);
    long long min = INT_MAX;
    int minIndex = -1;
    for(int i =start;i<n ;++i){
        if(a[i] < min){
            min = a[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int main(){

    std::cin >> n;

    int i = 0, j =0;
    for(i = 0; i < n; ++i){
        std::cin >> a[i];
    }


    int temp =0;
    // insertion sort
    for(i = 0;i<n-1;++i){
        int index = minIndex(i);
        std::swap(a[i],a[index]);

        for(temp = 0;temp<n;++temp){
            std::cout << a[temp]<< " ";
        }
        std::cout << std::endl;

    }

    return 0;
}