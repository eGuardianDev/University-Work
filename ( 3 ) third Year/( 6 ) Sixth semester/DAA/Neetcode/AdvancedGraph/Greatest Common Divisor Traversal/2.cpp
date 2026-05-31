#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;


bool dfs(int u ,int v, vector<vector<int>>& graph){
    stack<int> next;

    set<int> visited;

    next.push(u);

    while(!next.empty()){
        int c = next.top(); next.pop();
        if(visited.count(c)) continue;
        visited.insert(c);
        
        for(int adj : graph[c]){
            if(visited.count(adj)) continue;
            if(adj == v) return true;
            next.push(adj);
        }
    }
    return false;
}

bool canTraverseAllPairs(vector<int>& nums) {
    
    vector<vector<int>> graph(nums.size());

    for(int i =0;i<nums.size();++i){
        for(int j =i+1;j<nums.size();++j){
            if(gcd(nums[i],nums[j])>1){
                graph[j].push_back(i);
                graph[i].push_back(j);
            }        
        }
    }


    for(int i =0;i<graph.size();++i){
        for(int j =i+1; j<graph.size();++j){
            if(!dfs(i,j, graph)) return false;
        }
    }
    return true;
}

int main(){
    
    vector<int> nums = {4,3,12};

    cout << canTraverseAllPairs(nums) << endl;

    return 0;
}