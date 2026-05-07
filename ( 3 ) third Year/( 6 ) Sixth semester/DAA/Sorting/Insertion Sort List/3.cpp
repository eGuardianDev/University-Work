

#include <iostream>
#include <vector>

using namespace std;


void insertionSort(vector<int> & list){

    for(int i =0;i<list.size();++i){
        int el = list[i];

        int j = i;

        while(j > 0 && list[j-1] > list[j]){
            swap(list[j],list[j-1]);
            j--;
        }
    }

}


int main(){

    vector<int> list = {1231,312,30123123,124124,124,123,12,3};


    insertionSort(list);


    for(auto a : list){
        cout << a << " ";
    } cout << endl;

    return 0;
}