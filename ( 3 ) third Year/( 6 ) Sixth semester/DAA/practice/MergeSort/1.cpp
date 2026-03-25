

#include <iostream>
#include <vector>


int merge(int *arr, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<int> L(n1), R(n2);

    for(int i =0;i<n1;++i){
        L[i] = (arr[l+i]);
    }
    for(int i =0;i<n2;++i){
        R[i] = (arr[m+1+i]);
    }

    int i =0, j =0;
    int k = l;


    while( i<n1 && j<n2 ){
        if(L[i] < R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        ++k;
    }

    while(i <n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j <n2){
        arr[k] = R[j];
        j++;
        k++;
    }
    return 0;
}

int sort(int *arr, int l, int r){

    if(l >=r) return 0;

    int m = l + (r-l)/2;

    sort(arr, l, m);
    sort(arr, m+1, r);

    merge(arr,l,m,r);

    return 0;
}


int arr[] = {6,5,4,3,2,1};
int size = 6;

int main(){

    sort(arr, 0, size-1);

    for(int i =0;i<size;++i){
        std::cout << arr[i] <<" ";
    } std::cout << std::endl;

    return 0;
}