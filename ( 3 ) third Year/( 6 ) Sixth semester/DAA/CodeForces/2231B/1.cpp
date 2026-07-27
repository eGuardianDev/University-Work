

#include <iostream>

int main(){

    
    int t = 0;

    std::cin >> t;

    while(t){
        t--;

        int n ;
        std::cin >> n;

        int arr[n];

        for(int i =0;i <n;++i){
            std::cin>>arr[i];
        }

        int add = 0;

        for(int i =1 ;i<n;++i){
            add = std::max(add, arr[i] - arr[i-1]);
        }

        int flag= false;

        for(int i =1;i<n;++i){
        
            if(arr[i-1] > arr[i]){
                if(arr[i] + add >= arr[i-1]){
                    arr[i] += add;
                    continue;
                }
                flag = true;
                break;
            }
        }

        if(flag) std::cout << "NO" << std::endl;
        else std::cout << "YES" << std::endl;

    }
    return 0;
}