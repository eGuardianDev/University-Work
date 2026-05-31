#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;


int longestCommonSubsequence(string text1, string text2) {
    
    int n = text1.size();
    int m = text2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1,0));

    for(int i =1; i <= n; ++i){
        for(int j=1; j <= m; ++j){
            char c1 = text1[i-1];
            char c2 = text2[j-1];

            if(c1 == c2){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            if(c1 != c2){
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int main(){

    cout << longestCommonSubsequence("cat", "crabt") << endl;
    
    return 0;
}