class Solution {
public:


    stack<int> stk_res;
    vector<int> d_vis;

    bool dfs(vector<vector<int>>& graph, int curr){
        if(d_vis[curr] == 1) return true;
        if(d_vis[curr] == 2 ) return false;
        d_vis[curr] = 1;

        for(auto adj : graph[curr]){
           if( dfs(graph,adj)){
                return true;
           }
        }
        d_vis[curr] = 2;
        stk_res.push(curr);

        return false;
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

        d_vis.assign(n, false);

        for(int i =0;i<graph.size();++i){
            if(d_vis[i]) continue;
            if(dfs(graph, i)) return res;
        }

        while(!stk_res.empty())
        {
            res.push_back(stk_res.top());
            stk_res.pop();   
        }

        return res;
    }
};

