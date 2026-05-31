
#include <climits>
#include <iostream>
#include <queue>
#include <ratio>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

bool is_valid(vector<vector<int>> & height, int r,int c){
    if(r <0 || c <0) return false;
    if(r>= height.size()|| c>=height[r].size())return false;
    return true;
}


int Algo(vector<vector<int>> & heights){
    int res = 0;

    vector<vector<pair<int,int>>> graph(heights.size()*heights[0].size());
    
    int cols = heights[0].size();
    for(int r = 0; r<heights.size();++r){
        for(int c =0; c<heights[r].size();++c){
           int node = r * cols + c;
            int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
            for(auto& d : dirs){
                int nr = r + d[0], nc = c + d[1];
                if(is_valid(heights, nr, nc)){
                    graph[node].push_back({nr*cols+nc, abs(heights[r][c]-heights[nr][nc])});
                }
            }
        }
    }

    vector<int> dist(heights[0].size()*heights.size(),INT_MAX);
    vector<bool> visited(heights[0].size()*heights.size(),false);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[0] = 0;
    pq.push({0,0});
    // for(auto a: graph[0]){
    //     pq.push({a.second,a.first});
    // }

    
    while(!pq.empty())
    {
        auto [effort, node] = pq.top(); pq.pop();
        
        if(visited[node]) continue;
        visited[node] = true;

        int dest = heights.size() * cols - 1;
        if(node == dest) return effort;
        
        for(auto a: graph[node]){
            int new_effort = max(effort, a.second);
            pq.push({new_effort, a.first});
            // pq.push({a.second,a.first});
        }   
    }


    return res;
}

int main(){

    vector<vector<int>> heights = {
        {1,1,1},
        {3,2,4},
        {2,5,4}};
    cout << Algo(heights) << endl;
    return 0;
}