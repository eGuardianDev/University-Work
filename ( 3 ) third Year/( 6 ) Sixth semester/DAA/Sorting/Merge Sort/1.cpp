#include <iostream>
#include <vector>



using namespace std;


void merge(vector<int>& list, int l, int mid, int r){
    
    vector<int> L (mid-l+1), R(r-mid);


    for(int i = 0; i< L.size();++i){
        L[i] =(list[l+i]);
    }
    
    for(int i = 0; i< R.size();++i){
        R[i] = (list[mid+1+i]);
    }
    

    int i =0, j = 0;
    int k = l;
    while(i < L.size() && j < R.size()){
        if(L[i] <= R[j]){
            list[k] = L[i];
            i++;
        }else{
            list[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < L.size()){
        list[k] = L[i];
        i++;
        k++;
    }

    while(j < R.size()){
        list[k] = R[j];
        j++;
        k++;
    }



}

void MergeSort(vector<int>& list, int l, int r){
    if ( l >= r ) return ;

    int mid = l + (r-l)/2;
    MergeSort(list, l, mid);
    MergeSort(list, mid+1, r);

    merge(list, l,mid,r);
}


int main(){

    vector<int> list = {4,3,2,51,5,23,5,23,1,5,1,2,3,3,3,0};

    MergeSort(list, 0, list.size()-1);

    for(auto a :list){
        cout << a << " ";
    } cout << endl;


    return 0;
}