#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

vector<string>res;
vector<string> dfs(
    unordered_map<string, vector<string>> &graph,
    string u,
    vector<string> path,
    int end)
    {

    while(!graph[u].empty()){
        string v = graph[u].front();
        graph[u].erase(graph[u].begin());
        dfs(graph,v,path,end);
    }
    res.push_back(u);
    return {};
}


vector<string> findItinerary(vector<vector<string>>& tickets) {
   

    unordered_map<string, vector<string>> graph;

    for(auto a : tickets){
        string u = a[0];
        string v = a[1];
        graph[u].push_back(v);
    }


    for(auto &[a,b]:graph){
        sort(b.begin(),b.end());
    }

    vector<string> path;
    dfs(graph, "JFK",path,tickets.size()+1);

    reverse(res.begin(), res.end());
    return res;
}

int main(){

    vector<vector<string>> tickets = {{"BUF","HOU"},{"HOU","SEA"},{"JFK","BUF"}};

    // vector<vector<string>>  tickets = {{"HOU","JFK"},{"SEA","JFK"},{"JFK","SEA"},{"JFK","HOU"}};
    vector<string> path = findItinerary(tickets);

    for(auto a :path){
        cout << a << " ";
    }cout <<endl;



    return 0;
}