

#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

double dfs(unordered_map<string, unordered_map<string, double>> &graph,
    string u, 
    string v,
    unordered_set<string> &visited){
    
    if(!graph.count(u)) return -1;
    if(u == v) return 1;

    visited.insert(u);

    for(auto [neighbor, weight] : graph[u] ){
        if(visited.count(neighbor)) continue;
        double res = dfs(graph, neighbor,v, visited);
        if(res != -1) return weight * res;
    }
    
    return -1;
}

vector<double> calcEquation(vector<vector<string>>& equations,
     vector<double>& values, vector<vector<string>>& queries) {
    

    unordered_map<string, unordered_map<string, double>> graph;

    vector<double> res;
    for(int i =0;i<equations.size();++i){
        graph[equations[i][0]][equations[i][1]] = values[i];
        graph[equations[i][1]][equations[i][0]] = 1/values[i];
    }
    for(auto a : queries){
        unordered_set<string> visited;
        string u = a[0];
        string v = a[1];
        res.push_back(dfs(graph,u,v,visited));
    }
    return res;

}
int main(){

    vector<vector<string>> equations = 
    {{"a","b"},{"b","c"},{"ab","bc"}};
    vector<double> values = {4.0,1.0,3.25};
    
    
    vector<vector<string>> queries = {{"a","c"},{"b","a"},{"c","c"},{"ab","a"},{"d","d"}};


    for(auto a : calcEquation(equations, values, queries)){
        cout << a << " ";
    }cout <<endl;

    return 0;
}