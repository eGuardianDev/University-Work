class Solution {
public:

    bool hasCycle(vector<vector<int>>& graph, vector<int>& visited, int start){
        
        if(visited[start] == 1) return true;
        if(visited[start] == 2) return false;
        
        visited[start] = 1;

        for(int a : graph[start]){
            if(hasCycle(graph, visited, a)){
                return true;
            }
        }
        visited[start] = 2;

        return false;
    }

    stack<int> stk_res;
    vector<bool> d_vis;

    void dfs(vector<vector<int>>& graph, int curr){
        if(d_vis[curr]) return;
        d_vis[curr] = true;

        for(auto adj : graph[curr]){
            dfs(graph,adj);
        }
        stk_res.push(curr);

    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> res;
        int n = numCourses;
        
        vector<vector<int>> graph(n);
        vector<int> visited(n,0);
        for(int i = 0;i<prerequisites.size();++i){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            graph[v].push_back(u);
        }

        for(int i =0;i<graph.size();++i){
            if(visited[i]) continue;
            if(hasCycle(graph,visited,i)) return res;
        }

        d_vis.assign(n, false);

        for(int i =0;i<graph.size();++i){
            if(d_vis[i]) continue;
            dfs(graph, i);
        }

        while(!stk_res.empty())
        {
            res.push_back(stk_res.top());
            stk_res.pop();   
        }

        return res;
    }
};

