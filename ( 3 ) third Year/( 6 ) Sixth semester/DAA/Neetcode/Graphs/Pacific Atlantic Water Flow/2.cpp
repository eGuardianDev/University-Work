
#include <chrono>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

bool valid(int r,int c, vector<vector<int>>&heights){
    if(r < 0 || r >=heights.size()) return false;
    if(c < 0 || c >=heights[r].size()) return false;
    return true;
}

void dfs(int r,int c, int prev, vector<vector<int>> & heights, set<pair<int,int>> & res){

    if(!valid(r,c,heights)) return;
    if(heights[r][c] < prev) return;
    if(res.count({r,c})) return;

    res.insert({r,c});
    
    dfs(r+1,c,heights[r][c], heights,res);
    dfs(r-1,c,heights[r][c], heights,res);
    dfs(r,c+1,heights[r][c], heights,res);
    dfs(r,c-1,heights[r][c], heights,res);

}
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    
    // vector<vector<int>> pacific(heights.size(), vector<int>(heights[0].size(),0));

    set<pair<int,int>> pacific;
    set<pair<int,int>> atlantic;

    int rows = heights.size();
    int col = heights[0].size();

    for(int r =0;r<heights.size();++r){
        dfs(r,0,heights[r][0], heights,pacific);
        dfs(r,col-1,heights[r][col-1], heights,atlantic);
    }
    for(int c =0;c<heights[0].size();++c){
        dfs(0,c,heights[0][c], heights,pacific);
        dfs(rows-1,c,heights[rows-1][c], heights,atlantic);
    
    }

    vector<vector<int>> res;
    for(int r =0;r<heights.size();++r){
        for(int c=0;c<heights[r].size();++c){
            if(atlantic.count({r,c}) && pacific.count({r,c})){
                res.push_back({r,c});
            }
        }
    }

    


    return res;
}



int main(){

    vector<vector<int>> input =
  { {4,2,7,3,4},
  {7,4,6,4,7},
  {6,3,5,3,6}};
// {{1,2,2,3,5},
//  {3,2,3,4,4},
//  {2,4,5,3,1},
//  {6,7,1,4,5},
//  {5,1,1,2,4}};
    auto res = pacificAtlantic(input);

    for(auto r : input){
        for(auto c : r){
            cout << c << " ";
        } cout << endl;
    }
    cout <<endl;
    for(auto r : res){
        for(auto c : r){
            cout << c << " ";
        } cout << endl;
    }

    return 0;
}