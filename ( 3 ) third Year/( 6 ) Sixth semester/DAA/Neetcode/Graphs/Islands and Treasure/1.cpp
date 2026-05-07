class Solution {
public:

    bool check(vector<vector<int>>& grid, int r, int c){
        if(r < 0 || r >= grid.size()) return false;
        if(c <0 || c >= grid[r].size()) return false;
        return true;
    }

    void bfs(vector<vector<int>>&grid, vector<vector<bool>>&visited,int r,int c,int dept = -1){
        
        queue<pair<int,int>> stk;
        stk.push({r,c});
        int count = 0;
        while(!stk.empty()){
            if(count == 0){
                count = stk.size();
                dept+=1;
            }
            count--;
            auto& [r,c] = stk.front(); stk.pop();
            if(!check(grid, r,c)) continue;
            if(visited[r][c]) continue;
            visited[r][c] = true;

            if(grid[r][c] == -1) continue;

            if(grid[r][c] != 0){
                if(grid[r][c] > dept){
                    grid[r][c] = dept;
                }
            }

            stk.push({r+1,c});
            stk.push({r-1,c});
            stk.push({r,c+1});
            stk.push({r,c-1});
        }
        
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        for(int r= 0;r<grid.size();++r){
            for(int c= 0;c<grid[r].size();++c){
                if(grid[r][c]==0){ // chest found
                    vector<vector<bool>> visited(
                        grid.size(),
                        vector<bool>(grid[0].size(),false)
                    );
                    bfs(grid,visited,r,c);
                }
            }
        }        
    }
};

