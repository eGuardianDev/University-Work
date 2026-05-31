#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;


unordered_map<int,int> dp;

int helper(vector<int> &nums, int i , int end ){

    if(i>end) return 0;
    if(dp.count(i)) return dp[i];

    dp[i] = max(
        nums[i] + helper(nums, i+2, end),
        helper(nums,i+1,end)
    );

    return dp[i];
}
int rob(vector<int>& nums) {
    int end = nums.size();
    if (end == 1) return nums[0];
    int i =helper(nums, 0, end-2);
    dp.clear();
    int j =helper(nums,1,end-1);
    return max(i,j);
}


int main(){
    

    // vector<int> nums = {3,4,3};
    vector<int> nums = {2,9,8,3,6};

    cout << rob(nums) << endl;

    return 0;
}