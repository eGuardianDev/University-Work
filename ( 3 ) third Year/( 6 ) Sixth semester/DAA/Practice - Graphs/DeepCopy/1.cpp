#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;


void deepCopyHelper(int u, set<int> &visited, vector<vector<int>> &graph,vector<vector<int>>&res){
  if(visited.count(u)) return; // has u in visited
  visited.insert(u);

  for(auto v : graph[u]){
    res[u].push_back(v);
    deepCopyHelper(v, visited,graph,res);
  }
  
}

vector<vector<int>> deepCopy(int u, vector<vector<int>> & graph){

    vector<vector<int>> res(graph.size());
    set<int> visited; 
    deepCopyHelper(u,visited,graph, res);
    
    return res;
}

int main(){
        int n = 5;  // брой върхове

    // adjacency list
    vector<vector<int>> graph(n);

    // добавяне на ребра (ненасочен граф)
    graph[0].push_back(1);
    graph[1].push_back(0);

    graph[0].push_back(2);
    graph[2].push_back(0);

    graph[1].push_back(3);
    graph[3].push_back(1);

    graph[2].push_back(4);
    graph[4].push_back(2);

    // печат
    for (int i = 0; i < n; i++) {
        cout << i << ": ";

        for (int neighbor : graph[i]) {
            cout << neighbor << " ";
        }

        cout << endl;
    }

    vector<vector<int>> copy = deepCopy(1, graph);
    for(int i =0;i < n; ++i){
        cout << "[" << i << "] ";
        for(auto a : copy[i]){
            cout << a << " ";
        }cout <<endl;
        
    }

    return 0;
}