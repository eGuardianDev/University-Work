#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;


int maxi=0;
int sizes=0;
int indexs=0;
bool valid(string s, int index){
    if(index <0 || index >=s.size()) return false;
    return true;
}
void run(string s, int index){
    int i =0;
    while(valid(s,index-i) && valid(s,index+i)){
        cout<< s[index-i] <<" " << s[index+i] << endl;
        if(s[index-i] == s[index+i]){
            if((sizes + indexs) <= 2*i){
                indexs = index-i;
                sizes = 2*i;
            }
        }else break;
        ++i;
    }
    cout << "end" << endl;
}

string longestPalindrome(string s) {
    for(int i=0;i<s.size();++i){
        run(s,i);
    }
    string res;
    for(int i = indexs; i < indexs+sizes+1;++i){
        res += s[i];
    }
    return res;
}
int main(){
    cout << longestPalindrome("abbd");
    return 0;
}