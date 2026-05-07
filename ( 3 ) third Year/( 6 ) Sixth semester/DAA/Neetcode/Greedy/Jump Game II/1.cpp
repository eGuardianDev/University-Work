

#include <ios>
#include <iostream>
#include <unordered_map>
#include <vector>


using namespace std;

int jump(vector<int>& nums) {

    int n = nums.size();
    int farthest = 0;
    int possible = 0;
    int total = 0;

    for(int i =0;i< n-1;++i){
        farthest = max(farthest, i+nums[i]);
        if(i == possible){
            total+=1;
            possible = farthest;
        }
    }

    return total;
}

int main(){

    vector<int> list = {2,4,1,1,1,1};
    list = {2,1,2,1,0};

    auto res = jump(list);


    cout << res <<endl;


    return 0;
}