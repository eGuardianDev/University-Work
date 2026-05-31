#include <iostream>

#include <set>
#include <unordered_map>
#include <vector>


using namespace std;

vector<int> findRedundantConnection(vector<vector<int>>& edges) {

    vector<int> res;

    unordered_map<int, int> degrees;

    vector<vector<int>> graph;

    for(int i =0;i<edges.size();++i){
        while(graph.size() < edges[i][0]+1){
            graph.push_back(vector<int>());
        }
        graph[edges[i][0]].push_back(edges[i][1]);
        while(graph.size() < edges[i][1]+1){
            graph.push_back(vector<int>());
        }
        graph[edges[i][1]].push_back(edges[i][0]);
        
        degrees[edges[i][0]]++;
        degrees[edges[i][1]]++;
    }


    vector<int> leaves;

    for(int i =0;i<graph.size();++i){
        if(degrees[i] == 1){
            leaves.push_back(i);
        } 
    }

    while(true){
        vector<int> newLeaves;
        for(auto a : leaves){
            for(int i =0;i<graph[a].size();++i){
                if(--degrees[graph[a][i]] == 1){
                    newLeaves.push_back(graph[a][i]);
                }
            }
        }
        if(newLeaves.size() == 0) break;
        leaves = newLeaves;
    }

    set<int> cycleNodes;

    for(int i = 0; i < graph.size(); i++){
        if(degrees[i] > 1){
            cycleNodes.insert(i);
        }
    }

    for(int i = edges.size()-1; i >= 0; --i){
        vector<int>& data = edges[i];

        if(cycleNodes.count(data[0]) &&
        cycleNodes.count(data[1])){
            return data;
        }
    }
    return res;
}

int main(){

    vector<vector<int>> list = {{1,2},{1,3},{3,4},{2,4}};

    for(auto a : findRedundantConnection(list)){
        cout << a << " ";
    }cout << endl;
    return 0;
}