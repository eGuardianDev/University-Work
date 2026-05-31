#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;


int n;
int before(int i){
    if(i == 0) return n-1;
    return i-1;
}

int next(int i){
    if(i == n-1) return 0;
    return i+1;
}

int helper(vector<int> &nums, set<int> visited, int index ){
    int res = nums[index];
    visited.insert(index);
    visited.insert(next(index));
    visited.insert(before(index));

    int other = 0;
    for(int i =0;i<nums.size();++i){
        if(visited.count(i)) continue;
        other = max(other,helper(nums,visited,i));
    }

    return res + other;
}
int rob(vector<int>& nums) {
    n = nums.size();

    int res = 0;
    for(int i =0;i<n;++i){
        set<int> visited;
        res = max(res,helper(nums, visited,i));
    }

    return res;
}


int main(){
    

    // vector<int> nums = {3,4,3};
    vector<int> nums = {2,9,8,3,6};

    cout << rob(nums) << endl;

    return 0;
}