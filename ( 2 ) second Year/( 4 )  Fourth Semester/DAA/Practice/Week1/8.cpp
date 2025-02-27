#include <iostream>

int const maxx = 100;
int a[maxx];

int main(){

    int n = 0;
    std::cin >> n;

    int i = 0;

    int in = 0, j =0;
    for(i = 0; i < n; ++i){
        std::cin >> a[i];
    }


    // insertion sort
    for(i = 1;i<=n;++i){
        for(j = i-1;j>0;--j){
            if(i != j && a[j-1] > a[j]){
                std::swap(a[j-1], a[j]);
            }else{
                break;
            }
        }
    }


    for(i = 0;i<n;++i){
        std::cout << a[i]<< " ";
    }

    return 0;
}