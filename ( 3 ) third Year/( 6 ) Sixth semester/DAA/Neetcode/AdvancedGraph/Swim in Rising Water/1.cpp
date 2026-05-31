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

int is_valid(vector<vector<int>>& grid,int r,int c){
    if(r <0 || c <0)return -1;
    if(r >= grid.size() || c>= grid[r].size()) return -1;

    return r *grid[0].size() +c;
} 

int swimInWater(vector<vector<int>>& grid) {

    unordered_map<int, vector<pair<int,int>>> graph; //v,w

    vector<vector<int>> dist(grid.size(),vector<int>(grid[0].size(), INT_MAX));

    vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};

    int rows = grid.size();
    int cols = grid[0].size();

    for(int r =0;r<grid.size();++r){
        for(int c =0; c<grid.size();++c){
            int val = grid[r][c];

            for(auto& [r1,c1] : dirs){
                int index = is_valid(grid, r+r1, c+c1);
                if(index == -1) continue;

                graph[r*cols +c].push_back({index, grid[r+r1][c+c1]});
            }
        }
    }

    for(auto& [r,adj] : graph){
        cout << "[" << r <<"] ";
        for(int c =0;c<adj.size();++c){
            cout <<adj[c].first << " ";
        }cout <<endl;
    }


    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
    pq.push({grid[0][0],0,0});
    dist[0][0] = grid[0][0];

    set<pair<int,int>> visited;
    int max_flow =0;
    while(!pq.empty()){
        auto [w,i,j] = pq.top();pq.pop();

        if(visited.count({i,j})) continue;
        visited.insert({i,j});
        max_flow = max(w,max_flow);

        if(i == grid.size()-1 && j == grid.size()-1){
            return max_flow;
        }
        for(auto& [r1,c1] : dirs){
            int index = is_valid(grid, i+r1, j+c1);
            if(index == -1) continue;

            pq.push({grid[i+r1][j+c1],i+r1,j+c1});
        }
    }


    return max_flow;
}
int main(){
    vector<vector<int>> grid = {
  {0,1,2,10 },
  {9,14,4,13},
  {12,3,8,15},
  {11,5,7,6 }};
    
  cout << endl << swimInWater(grid) << endl;
  return 0;
}