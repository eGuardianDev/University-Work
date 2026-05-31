#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;


int helper(vector<int>& nums, int target, unordered_map<int, int> & dp){

    if(target <0) return 0;
    if(dp.count(target)) return dp[target];

    int res = 0;
    for(auto num : nums){
        int curr = target - num;
        res+=helper(nums,curr,dp);
    }
    dp[target] = res;
    return dp[target];
}

int combinationSum4(vector<int>& nums, int target) {

    unordered_map<int, int> dp;
    dp[0] = 1;
    return helper(nums, target,dp);
}

int main(){
    
    vector<int> nums = {3,1,2};
    int target = 4;

    cout << combinationSum4(nums, target) << endl;

    return 0;
}