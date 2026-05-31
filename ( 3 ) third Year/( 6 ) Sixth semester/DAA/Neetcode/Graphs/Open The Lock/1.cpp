#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

vector<string> children(string word){
    vector<string> res;

    for(int i =0;i<word.size();++i){
        char a = word[i] +1;
        char b = word[i] -1;
        if(a == '9'+1){
            a = '0';
        }
        if(b =='0'-1){
            b = '9';
        }
        string r;
        string r1;
        for(int j =0;j<word.size();++j){
            if(j ==i){
                r +=a; 
                r1 +=b; 
            }else{
                r += word[j];
                r1 += word[j];
            }
        }
        res.push_back(r);
        res.push_back(r1);
    }

    return res;
}

int openLock(vector<string>& deadends, string target) {
    
    for(int i =0; i<deadends.size();++i){
        if(deadends[i] == "0000") return -1;
    }
    
    queue<pair<string,int>> next;

    next.push({"0000",0});

    set<string> visited;

    for(auto a : deadends){
        visited.insert(a);
    }


    while(!next.empty()){
        auto [word, level] = next.front(); next.pop();

        if(word == target) return level;

        for(auto child : children(word)){
            if(!visited.count(child)){
                visited.insert(child);
                next.push({child,level+1});
            }
        }

    }

    return -1;
}
int main(){

    vector<string> locks = {"1234"};
    cout << openLock({locks}, "1235") << endl;

    return 0;
}