
#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

bool dfs(vector<vector<int>> & graph, vector<int> &visited,int u ){

    visited[u] = 1;
    for(auto v : graph[u]){
        if(visited[v] == 1) return false;
        if(visited[v] == 2) continue;
        if(!dfs(graph,visited,v)) return false;
    }
    visited[u] = 2;

    return true;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    
    vector<int> visited(graph.size(),0);

    for(int i =0;i<graph.size();++i){
        if(visited[i] == 0){
            dfs(graph,visited,i);
        }
    }

    vector<int> res;
    for(int i =0;i<graph.size();++i){
        if(visited[i] == 2){
            res.push_back(i);
        }
    }

    return res;
}


int main(){
    
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};

    for(auto a :eventualSafeNodes(graph)){
        cout << a << " ";
    } cout << endl;

    return 0;
}