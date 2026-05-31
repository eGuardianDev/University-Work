
#include <climits>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
#include <set>

using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    int sum =0;

    vector<vector<pair<int,int>>> graph(n);
    for(int i =0;i<flights.size();++i){
        int u = flights[i][0];
        int v = flights[i][1];
        int w = flights[i][2];
        graph[u].push_back({v,w});
    }

    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    //w,k,u
    pq.push({0,k,src});

    while(!pq.empty()){
        auto [w, stops, u] = pq.top(); pq.pop();
        if(u == dst) return w;
        
        if(stops <0) continue;

        for(int i =0;i<graph[u].size();++i){
            int v = graph[u][i].first;
            int w1 = graph[u][i].second;
            pq.push({w+w1,stops-1,v});;
        }
    }

    
    return -1;
}

int main(){
    
    int n = 4;
    vector<vector<int>> flights = {{0,1,200},{1,2,100},{1,3,300},{2,3,100}};
    int src = 0;
    int dst = 3;
    int k = 1;

    cout << findCheapestPrice(n, flights, src,dst,k) << endl;
    return 0;
}