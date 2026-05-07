
#include <iostream>

#include <vector>

using namespace std;


int partiction(vector<int> & list, int l, int r){
    
    int element = list[r];

    int i =l,j=l;

    for(;j < r;++j){
        if(list[j] < element){
            swap(list[j],list[i]);
            ++i;
        }
    }

    // ++i;
    swap(list[i],list[r]);

    return i;
}


void QuickSort(vector<int>& list, int s, int n){

    if ( s < n){

        int pi = partiction(list, s, n);

        QuickSort(list, s, pi-1);
        QuickSort(list, pi+1, n);
    }
}

int main(){

    vector<int> list = {4,2,5,192,3044,283,4081,4,3,2,5,5,5,4,3,0};

    QuickSort(list, 0, list.size()-1);

    for(auto a: list){
        cout << a << " "; 
    }cout << endl;

    return 0;
}