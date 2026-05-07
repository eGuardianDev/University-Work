#include <climits>
#include <iostream>
#include <vector>

using namespace std; 


vector<int> countingSort(vector<int>& list){

    int max_ = INT_MIN;

    for(int i =0;i<list.size();++i){
        max_ = max(max_, list[i]);
    }


    vector<int> cnt_ans(max_+1,0);


    for(int i =0;i<list.size();++i){
        cnt_ans[list[i]]++;
    }

    for(int i =1; i< max_+1;++i){
        cnt_ans[i] += cnt_ans[i-1];
    }


    vector<int> ans_list(list.size(),0);

    // for(int i =list.size()-1; i >= 0;--i){
    //     ans_list[cnt_ans[list[i]] -1 ] = list[i];
    //     cnt_ans[list[i]]--;
    // }

    for(int i =0;i <list.size()-1; ++i){
        ans_list[cnt_ans[list[i]] -1 ] = list[i];
        cnt_ans[list[i]]--;
    }

    return ans_list;
}

int main(){

    vector<int> list = {4,2,5,6,1,7,2,8,3,4,5,0};

    auto ans = countingSort(list);

    for(auto a : ans){
        cout << a << " ";
    }cout << endl;


    return 0;
}