
#include <iostream>
#include <queue>
#include <stack>
#include <vector>


using namespace std;

queue<pair<int,int>> stk;
int max_min = -1;

bool is_valid(
    vector<vector<int>> & grid,
    int r,int c){

    if(r < 0 || c < 0) return false;
    if(r >= grid.size() || c >= grid[r].size()) return false;
    return true;
}

void bfs(vector<vector<int>> & grid){
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(),false));

    int count = stk.size();
    int dept = 0;
    max_min = dept;

    while(!stk.empty()){
        if(count == 0){
            count = stk.size();
            dept++;
            max_min = dept;
        }
        count--;

        auto [r,c] = stk.front(); stk.pop();


        if(grid[r][c] == 1){
            grid[r][c] = 2;
        } 
        // if(grid[r][c] == 2) continue;
        if(grid[r][c] == 0) continue;

        if(is_valid(grid, r+1, c)&& !visited[r+1][c] &&grid[r+1][c]==1) 
        {
            visited[r+1][c] = true;
            grid[r+1][c] = 2;
            stk.push({r+1,c});
        }
        if(is_valid(grid, r-1, c)&& !visited[r-1][c] &&grid[r-1][c]==1) 
        {
            visited[r-1][c] = true;
            grid[r-1][c] = 2;
            stk.push({r-1,c});
        }
        if(is_valid(grid, r, c+1)&& !visited[r][c+1] &&grid[r][c+1]==1) 
        {
            visited[r][c+1] = true;
            grid[r][c+1] = 2;
            stk.push({r,c+1});
        }
        if(is_valid(grid, r, c-1)&& !visited[r][c-1] &&grid[r][c-1]==1) 
        {
            visited[r][c-1] = true;
            grid[r][c-1] = 2;
            stk.push({r,c-1});
        }
    }

}

int orangesRotting(vector<vector<int>>& grid) {
    for(int r = 0; r < grid.size();++r){
        for(int c = 0;c< grid[r].size();++c){
            if(grid[r][c] == 2) {
                stk.push({r,c});
            }        
        }
    }
    bfs(grid);

    for(int r = 0; r < grid.size();++r){
        for(int c = 0;c< grid[r].size();++c){
            if(grid[r][c] == 1) {
                return -1;
            }        
        }
    }
    return max_min;
}


int main(){

    // vector<vector<int>> list = {{1,1,0},{0,1,1},{0,1,2}};
    vector<vector<int>> list = {{1,0,1},{0,2,0},{1,0,1}};
    cout << orangesRotting(list);

    return 0;
}