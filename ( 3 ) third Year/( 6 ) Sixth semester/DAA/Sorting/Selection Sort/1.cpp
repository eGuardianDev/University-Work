#include <iostream>
#include <vector>

using namespace std;


void selectionSort(vector<int>& list){

    int n = list.size();
    for(int i =0;i<n;++i){
        int min_ =i;


        for(int j = i+1; j <n;++j){
            if(list[min_] > list[j]){
                min_ = j;
            }
        }

        swap(list[min_], list[i]);
    }
}

int main(){

    vector<int> list = {5,3,1,6,8,3,4,5,2};

    selectionSort(list);

    for(auto a : list){
        cout << a << " ";
    } cout << endl;
    return 0;
}