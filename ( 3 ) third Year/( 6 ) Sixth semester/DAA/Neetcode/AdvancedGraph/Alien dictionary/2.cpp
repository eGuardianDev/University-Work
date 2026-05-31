
#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

bool dfs(unordered_map<char,vector<char>>& graph_,
    unordered_map<char, int> &visited, char u,
    string &res){

    if(visited.count(u)){
        if(visited[u] == 1) return false; 
        if(visited[u] == 2) return true; 
    }
    visited[u] = 1;
    for(auto v : graph_[u]){
        
        if(!dfs(graph_,visited,v,res)) return false;
    }

    
    res.push_back(u);
    visited[u] = 2;

    return true;
}

string foreignDictionary(vector<string>& words) {
    
    unordered_map<char, vector<char>> graph_has;
    
    for(int i =0;i<words.size();++i){
        for(int j =0;j<words[i].size();++j){
            graph_has[words[i][j]];
        }
    }

    for(int i =0;i<words.size()-1;++i){
        int min_ = min(words[i].size(), words[i+1].size());
        bool found = false;
        for(int k = 0; k < min_;++k){
            if(words[i][k] != words[i+1][k]){
                graph_has[words[i][k]].push_back(words[i+1][k]);
                found = true;
                break;
            }
        }  
        if(!found && words[i].size() > words[i+1].size()) return "";
    }


    unordered_map<char, int> visited;

    for(auto &[u,adj] : graph_has){
        visited[u] = 0;
    }

    string res;
    for(auto [u,adj] :graph_has){
        if(visited[u]==0)
            if(!dfs(graph_has,visited,u,res)) return "";
    }


    reverse(res.begin(), res.end());
    return res;
}


int main(){

    vector<string> words =//s {"hrn","hrf","er","enn","rfnn"};
    {"wrtkj","wrt"};
    // vector<string> words = {"z","o"};

    cout << foreignDictionary(words) << endl;
    return 0;
}