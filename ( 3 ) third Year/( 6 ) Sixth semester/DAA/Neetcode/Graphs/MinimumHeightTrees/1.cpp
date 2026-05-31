


#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);

        stack<int> stk;
        unordered_map<int, int> node_outs;

        for(int i =0;i<edges.size();++i){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);

            node_outs[edges[i][0]]++;
            node_outs[edges[i][1]]++;
        }

        vector<int> list;

        for(int i =0;i<graph.size();++i){
            if(graph[i].size() == 1) list.push_back(i);
        }

        int remaining = n;
        
        while(remaining>2){
            remaining -= list.size();
            
            vector<int> newList;
            for(auto leaf : list){
                for(int adj : graph[leaf]){
                    if(--node_outs[adj] == 1){
                        newList.push_back(adj);
                    }
                }
            }
            list = newList;
        }

        return list;

    }
int main(){


    vector<vector<int>> args = {{0,1},{3,1},{2,3},{4,1}};

    auto res = findMinHeightTrees(5,args);

    for( auto a : res){
        cout << a << " ";
    }cout <<endl;

    return 0;
}


