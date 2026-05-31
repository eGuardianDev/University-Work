
#include "../Graph.hpp"
#include <climits>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

vector<int> Prim(vector<vector<pair<int,int>>> & graph){
   
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    vector<int> res;

    vector<int> dist(graph.size(), INT_MAX);
    vector<int> parent(graph.size(),-1);

    dist[0] = 0;
    pq.push({0,0}); // w,u

    vector<bool> visited(graph.size(),false);

    while(!pq.empty()){
        auto [w,u] = pq.top(); pq.pop();

        if(visited[u]) continue;
        visited[u] = true;

        res.push_back(u);

        for(auto [v,weight] : graph[u]){
            if(!visited[v] && weight < dist[v]){
                dist[v] = weight;
                parent[v] = u;
                pq.push({weight,v});
            }
        }

    }

    // int prices =0;
    // for(auto price: dist){
    //     prices+=price;
    // }
    // cout << "cost " << prices << endl;
    return res;
}

void display(vector<int> res){
    for(auto a :res){
        cout << a << " ";
    }cout << endl;
}

int main(){

    display(Prim(graph1));
    display(Prim(graph2));
    display(Prim(graph3));
    
    return 0;
}