#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;


unordered_map<int, int> dp;
int helper(int n, int curr,vector<int> &pos){

    if(curr > 0) return INT_MAX-10000;
    if(curr == n) return 1;
    if(dp.count(n)) return dp[n];

    int res =INT_MAX;
    for(int i =0;i<pos.size();++i){
        res = min(res,helper(n,curr+pos[i],pos)+1);
    }

    dp[n] = res;
    return res;
}

int numSquares(int n) {
    

    vector<int> pos;

    for(int i =1;i*i<n;i +=1){
        pos.push_back(i*i);
    }

    return helper(n,0,pos);
}

int main(){
    
    cout << numSquares(13) << endl;
    return 0;
}