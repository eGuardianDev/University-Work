
#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;


int change(int amount, vector<int>& coins) {
    if(amount ==0 )return 1;
    vector<vector<int>> dp(coins.size(), vector<int>(amount+1,0));
    
    for(int j = 0;j<=amount;++j){
        if(coins[0] > j){
            continue; // cannot put
        }
        else if(coins[0] == j){
            dp[0][j] = 1;
        }
        else{
            dp[0][j] = dp[0][j] +1*dp[0][j-coins[0]];
        }
    }

    for(int i =1;i<coins.size();++i){
        for(int j =0;j<=amount;++j){
            if(coins[i] > j){
                dp[i][j] = dp[i-1][j];
            }
            else if(coins[i] == j){
                dp[i][j] = dp[i-1][j] + 1;
            }
            else{
                dp[i][j] = dp[i-1][j] +1*dp[i][j-coins[i]];
            }
        }
    }

    return dp[coins.size()-1][amount];
}


int main(){
 
    vector<int> coins = {1,2,3}; int amount =4;
    // vector<int> coins = {2,4}; int amount = 7;
    cout << change(amount, coins);

    return 0;
}