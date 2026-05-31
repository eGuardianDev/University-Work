#include <algorithm>
#include <functional>
#include <iostream>

#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int,int> dp;

// int helper(int n ){
    // if(n ==0) return 0;
    // if(n ==1) return 1;
    // if(n ==2) return 1;

    // return tribonacci(n-1) + tribonacci(n-2) +tribonacci(n-3);
// }

int helper(int n ){
    
    if(dp.count(n)) return dp[n];
    dp[n] = helper(n-1) + helper(n-2) + helper(n-3);

    return dp[n];
}
int tribonacci(int n) {
    
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    
    return helper(n);
}

int main(){


    int n = 21;
    cout << tribonacci(n) << endl;
    return 0;
}