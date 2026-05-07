
#include <iostream>
#include <vector>

using namespace std;

int particion(vector<int>& list, int l, int r){
    
    int pivot = list[r];

    int i = l;

    for(int j = l; j<r;++j){
        if(list[j] < pivot){
            swap(list[i],list[j]);
            i++;
        }
    }
    swap(list[i], list[r]);
    return i;
}

void quickSort(vector<int>& list,int start,int end ){
    
if( start >= end) return;

   int parti = particion(list,start, end);

   quickSort(list, start, parti-1);
   quickSort(list, parti+1, end);

}

int main(){

    vector<int> list = {1,6,4,2,7,3,2,1,6,8};

    quickSort(list,0, list.size()-1);
    for(auto a: list){
        cout << a << " ";
    } cout << endl;

    return 0;
}