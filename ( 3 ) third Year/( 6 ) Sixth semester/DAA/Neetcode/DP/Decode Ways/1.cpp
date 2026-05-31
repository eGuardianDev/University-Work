#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<char, int> maps;
// for(int i = 1;i<=26;++i){
    //     maps['a'+i-1] = i;
    // }


unordered_map<int,int> dp;

int helper(string s, int index){
    
    if(index >= s.size()) return 1;
    if(dp.count(index)) return dp[index];
    if(s[index] == '0') return 0;

    int res = helper(s,index+1);

    if(index+1 < s.size()){
        if(s[index] == '1' || (s[index] == '2' && (s[index+1] >='0' && s[index+1] <= '6'))){
            res += helper(s, index+2);
        }
    }
    dp[index] = res;
    return res;
}
    
int numDecodings(string s) {

    return helper(s, 0);
}

int main(){

    cout << numDecodings("1234");
    
    return 0;
}