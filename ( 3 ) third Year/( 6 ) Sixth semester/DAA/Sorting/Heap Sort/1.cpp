#include <iostream>
#include <vector>

using namespace std;


void heapify(vector<int>& list, int n, int i){
    int largest = i;

    int l = 2 *i +1;
    int r = 2 *i +2;


    if(l < n && list[l] >list[largest]){
        largest = l;
    }

    if(r < n && list[r] > list[largest]){
        largest = r;
    }


    if(largest != i){
        swap(list[i], list[largest]);
        heapify(list,n,largest);
    }

}

void heapSort(vector<int>& list){
    int n = list.size();

    // Build Max Heap
    for(int i = n/2 -1; i>=0; i--){
        heapify(list, n, i);
    }

    // Heap Sort
    for(int i = n-1; i>0;--i){
        swap(list[0],list[i]);

        heapify(list,i,0);
    }



}

int main(){

    vector<int> list = {5,3,1,6,8,3,4,5,2};

    heapSort(list);

    for(auto a : list){
        cout << a << " ";
    } cout << endl;
    return 0;
}