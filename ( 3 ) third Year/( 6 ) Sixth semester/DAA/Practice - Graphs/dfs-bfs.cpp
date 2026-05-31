
#include "Graph.hpp"
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

vector<int> DFS(vector<vector<pair<int,int>>> & graph){
    stack<int> next; 

    next.push(0);

    vector<int> res;
    vector<bool> visited(graph.size());

    while(!next.empty()){
        // take element
        auto u = next.top(); next.pop();
        
        // select to not repeat
        if(visited[u]) continue;
        visited[u] = true;
        
        // push to result
        res.push_back(u);

        // add all adjecent 
        for(auto v : graph[u]){
            next.push(v.first);
        }
    }
    
    return res;
}
vector<int> BFS(vector<vector<pair<int,int>>> & graph){
    queue<int> next; 

    next.push(0);

    vector<int> res;
    vector<bool> visited(graph.size());

    while(!next.empty()){
        // take element
        auto u = next.front(); next.pop();
        
        // select to not repeat
        if(visited[u]) continue;
        visited[u] = true;
        
        // push to result
        res.push_back(u);

        // add all adjecent 
        for(auto v : graph[u]){
            next.push(v.first);
        }
    }
    
    return res;
}

void display(vector<int> res){
    for(auto a :res){
        cout << a << " ";
    }cout << endl;
}

int main(){

    cout << "DFS: "<< endl;
    display(DFS(graph1));
    display(DFS(graph2));
    display(DFS(graph3));
    
    cout << "BFS: "<< endl;
    display(BFS(graph1));
    display(BFS(graph2));
    display(BFS(graph3));
    
    return 0;
}