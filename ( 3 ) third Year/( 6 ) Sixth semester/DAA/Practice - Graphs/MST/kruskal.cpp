
#include "../Graph.hpp"
#include <climits>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;


int Find(vector<int> &parent, int u){
    if(parent[u] == u) return u;
    
    return (parent[u] = Find(parent, parent[u]));
}

void Union(vector<int> &parent, vector<int> &rank, int u, int v){

    int u_p = Find(parent, u);
    int v_p = Find(parent, v);

    if(u_p == v_p) return;
    
    if(rank[u_p] < rank[v_p]){
        // swap(u, v);        
        swap(u_p, v_p);        
    }

    parent[v_p] = u_p;
    
    if(rank[u_p] == rank[v_p]) rank[u_p] = rank[u_p]+1;

}


vector<pair<int,int>> Kruskal(vector<vector<pair<int,int>>> & graph){

    vector<pair<int,int>> res;

    vector<int> parent;
    vector<int> rank(graph.size(),0);
    for(int i =0;i<graph.size();++i){
        parent.push_back(i);
    }
    
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
    
    for(int u =0;u<graph.size();++u){
        for(int j =0; j<graph[u].size();++j){
            pq.push({graph[u][j].second, u, graph[u][j].first});
        }    
    }

    int count =0;
    int n = graph.size();

    

    while(!pq.empty() || count != n-1){
        auto [w, u, v] = pq.top(); pq.pop();

        if(Find(parent,u) != Find(parent,v)){
            res.push_back({u,v});
            Union(parent, rank,  u,  v);
            count++;
        }
    }

    

    return res;
}

void display(vector<pair<int,int>> res){
    for(auto [a,w] :res){
        cout << a <<":" << w<< " ";
    }cout << endl;
}

int main(){

    display(Kruskal(graph1));
    display(Kruskal(graph2));
    display(Kruskal(graph3));
    
    return 0;
}