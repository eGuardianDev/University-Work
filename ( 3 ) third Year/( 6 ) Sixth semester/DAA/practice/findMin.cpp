#include <iostream>


int findMin(int * arr, int len){
    int min = 0;

    for(int i= 0;i<len;++i){
        if( arr[i] < arr[min]){
            min = i;
        }
    }
    return min;
}


int main(){

    int arr_size = 4;
    int * arr = new int[]{5,8,1,3};

    int min = findMin(arr,arr_size);

    for(int i =0;i<arr_size; ++i){
        if(min == i){
            std::cout <<'[';
        }
        std::cout << arr[i];
        if(min == i){
            std::cout <<']';
        }
        std::cout << " ";
    }
    std::cout<< "\nminimal value is at index " << min+1 << std::endl;

    return 0;
}