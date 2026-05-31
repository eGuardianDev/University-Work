#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;



bool helper(string s, int index, string curr, set<string> &words){

    if(words.count(curr)){
        if(helper(s,index+1,"",words)) return true;
        if(helper(s,index+1,curr,words)) return true;
    }
    if(index >= s.size()) return false;
    
    curr += s[index];
    return helper(s,index+1,curr,words);
}

bool wordBreak(string s, vector<string>& wordDict) {

    set<string> words;

    for(auto a : wordDict){
        words.insert(a);
    }

    return helper(s,0, "", words);    
}

int main(){
    
    vector<string> wordDict = {"aaaa","aaa"};
    cout << wordBreak("aaaaaaa", wordDict) <<endl;

    return 0;
}