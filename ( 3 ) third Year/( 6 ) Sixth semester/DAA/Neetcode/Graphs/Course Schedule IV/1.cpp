
#include <climits>
#include <ios>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    
    vector<vector<int>> graph(numCourses);
    unordered_map<int, int> indegree;


    vector<bool> res(queries.size(),false);
    vector<int> topoSort;

    int edges = 0;

    for(int i = 0; i< prerequisites.size();++i){
        int u = prerequisites[i][0];
        int v = prerequisites[i][1];
        graph[u].push_back(v);
        indegree[v]++;
        edges++;
    }
    
    queue<int> q;
    for(int i = 0; i < numCourses; i++)
        if(indegree[i] == 0) q.push(i);
    while(!q.empty()){

        int node = q.front(); q.pop();

        topoSort.push_back(node);

        for(int neighbor : graph[node]){
            if(--indegree[neighbor] == 0){
                q.push(neighbor);
            }
        }
    }
    

    vector<vector<bool>> reachable(numCourses, vector<bool>(numCourses, false));


    for(int i = topoSort.size()-1; i>=0; --i){
        int node = topoSort[i];

        for(int neighbor: graph[node]){
            reachable[node][neighbor] = true;
                
            for(int j = 0; j < numCourses; ++j)
                if(reachable[neighbor][j]) reachable[node][j] = true;
        }

    }

    for(int k =0;k<queries.size();++k){
        res[k] = reachable[queries[k][0]][queries[k][1]];
    }

    return res;
}


int main(){

    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1,0},{2,1},{3,2}};
    vector<vector<int>> queries = {{0,1},{3,1}};


    cout << boolalpha;
    for(auto a : checkIfPrerequisite(numCourses, prerequisites, queries)){
        cout << a << " ";
    }cout <<endl;

    return 0;
}