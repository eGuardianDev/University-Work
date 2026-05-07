

#include <iostream>
#include <vector>

using namespace std;

void InsertionSort(vector<int>& arr){

    for(int i =0;i<arr.size();++i){
        int j =i;

        while (j >0 && arr[j] < arr[j-1]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}

int main(){

    std::vector<int> arr = {5,4,1,2,6,8,3,2,2};
    InsertionSort(arr);

    for(auto el : arr){
        cout << el << " ";
    }cout << endl;


    return 0;
}