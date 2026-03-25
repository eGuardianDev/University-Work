#include <iostream>



int arr[] = {
    12, 45, 3, 89, 27, 64, 91, 5, 38, 72,
    14, 66, 29, 8, 57, 93, 41, 76, 2, 60,
    18, 33, 95, 7, 54, 81, 26, 47, 69, 11,
    90, 24, 52, 73, 36, 1, 84, 58, 16, 67,
    39, 92, 6, 71, 44, 19, 62, 87, 30, 53,
    75, 4, 98, 21, 63, 40, 77, 9, 55, 82,
    13, 68, 34, 96, 22, 59, 74, 17, 50, 88,
    31, 65, 10, 83, 46, 20, 70, 97, 15, 61,
    42, 78, 23, 56, 94, 28, 48, 79, 35, 80
};

int size = sizeof(arr) / sizeof(arr[0]);

void print(int *arr, int size_ ){

    for(int i =0;i<size_;++i){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


// void sort(int *arr, int size_){
    
//     for(int i =0;i<size_;++i){
//         int temp_i = i;
//         for(int j =temp_i ;j>=0;--j){
//             {
//             if(arr[j] > arr[temp_i])
//                 std::swap(arr[temp_i],arr[j]);
//                 temp_i = j;
//             }
//         }
//     }
// }

void sort(int *arr,int size_){
    for(int i =1; i<size_; ++i){
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] =arr[j];
            --j;
        }
        arr[j+1] = key;
    }
}


int main(){

    std::cout << "Pre sort:  ";
    print(arr,size);


    sort(arr,size);

    std::cout << "Post sort: ";
    print(arr,size);


    return 0;
}