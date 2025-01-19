
#include <ios>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool dfsValid( vector<vector<int>>& edges,  unordered_map<int,bool> &visited, int source, int destination ){
    if(destination == source){
        return true;
    }
    if(visited[source]){
        return false;
    }

    visited[source] = true;
    for(int i =0; i< edges[source].size();++i){
        int to = edges[source][i];
        if(visited[to] == false){
            if(dfsValid(edges, visited, to, destination)){
                return true;
            }
        }
    }
    return false;
}

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    unordered_map<int,bool> visited(n);
    vector<vector<int>> list(n);
    for(int i =0;i<edges.size();++i){
        int from = edges[i][0];
        int to = edges[i][1];
        list[from].push_back(to);
        list[to].push_back(from);
    }

    return dfsValid(list,visited, source, destination);
}

int main(){
    
    
    // int n = 3, source = 0, destination = 2;
    // vector<vector<int>> edges = {{0,1},{1,2},{2,0}};
    int n = 10, source =7, destination = 5;
    vector<vector<int>> edges = {{0,7},{0,8},{6,1},{2,0},{0,4},{5,8},{4,7},{1,3},{3,5},{6,5}};
    std::cout << boolalpha << validPath(n,edges,source, destination) << endl;
    return 0;
}