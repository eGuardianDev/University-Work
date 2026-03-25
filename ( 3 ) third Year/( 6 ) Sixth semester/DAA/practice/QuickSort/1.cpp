#include <iostream>



int arr[] = { 5, 4, 2, 8, 3, 1, 0};

int size = 7;


void print(int *arr, int size_ ){

    for(int i =0;i<size_;++i){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


int particioning(int *arr, int l, int r){

    int pivot = arr[r];

    int i = l-1;

    for(int j= l; j<= r-1; j++){
        if(arr[j] < pivot){
            i++;
            std::swap(arr[i],arr[j]);
        }
    }

    std::swap(arr[i+1], arr[r]);
    return i+1;
}


void sort(int *arr, int l, int r){

    if( l < r){
        int data = particioning(arr, l, r);

        sort(arr, l, data-1);
        sort(arr, data+1, r);
    }

}


int main(){

    print(arr,size);
    sort(arr,0,size);
    print(arr,size);



    return 0;
}