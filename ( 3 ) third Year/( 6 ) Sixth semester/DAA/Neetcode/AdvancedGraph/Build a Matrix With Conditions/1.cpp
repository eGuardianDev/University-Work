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

// bool dfs_cycle(int u, vector<vector<int>>& graph, set<int> visited){

//     if(visited.count(u)) return true;
//     visited.insert(u);

//     for(auto v : graph[u]){
//         if(visited.count(u)) return true;
//         if(dfs_cycle(u, graph, visited)) return true;
//     }

//     return false;
// }

vector<int> topoSort(vector<vector<int>> & graph, unordered_map<int, int> indecies){
    vector<int> res;
    queue<int> q;
    
    for (auto &[node, deg] : indecies) {
        if (deg == 0) {
            q.push(node);
        }
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();

        res.push_back(u);

        for(auto v : graph[u]){
            indecies[v]--;
            if(indecies[v] ==0){
                q.push(v);
            }
        }
    }

    if(res.size()!= indecies.size()){
        return {};
    }

    return res;
}

vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
    
    vector<vector<int>> graphRows(k+1);

    unordered_map<int, int> indecies;

    for (int i = 1; i <= k; i++) {
        indecies[i] = 0;
    }
    for(auto &a :rowConditions){
        int u = a[0];
        int v = a[1];
        
        graphRows[u].push_back(v);
        indecies[v]++;
    }



    vector<int> topoRow = topoSort(graphRows, indecies);
    
    if(topoRow.size() == 0) return {}; 


    vector<vector<int>> graphCols(k+1);

    unordered_map<int, int> indecies2;

    for (int i = 1; i <= k; i++) {
        indecies2[i] = 0;
    }

    for(auto &a :colConditions){
        int u = a[0];
        int v = a[1];
        
        graphCols[u].push_back(v);
        indecies2[v]++;
    }



    vector<int> topoCols = topoSort(graphCols, indecies2);

    if(topoCols.size() == 0) return {}; 


    unordered_map<int, pair<int,int>> mapping;

    for(int r =0;r<topoRow.size();++r){
        mapping[topoRow[r]] = {r,-1};
    }
    for(int c =0;c<topoCols.size();++c){
        mapping[topoCols[c]] = {mapping[topoCols[c]].first,c};
    }

    
    vector<vector<int>> res(k, vector<int>(k,0));

    for(auto [a,b]:mapping){
        // cout << a <<" " << b.first << "," << b.second <<endl;
        res[b.first][b.second] = a;
    }

    return res;
}

int main(){
    int k = 3;
    vector<vector<int>> rowConditions = {{2,1},{1,3}};
    vector<vector<int>> colConditions = {{3,1},{2,3}};


    for(auto a : buildMatrix(k, rowConditions, colConditions)){
        cout << "[ ";
        for(auto b:a){
            cout << b<< " ";
        }
        cout << "]" <<endl;

    }


    return 0;
}