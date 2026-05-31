
// #include <climits>
// #include <iostream>
// #include <ratio>
// #include <unordered_map>
// #include <vector>
// #include <set>

// using namespace std;

// bool is_valid(vector<vector<int>> & height, int r,int c){
//     if(r <0 || c <0) return false;
//     if(r>= height.size()|| c>=height[r].size())return false;
//     return true;
// }

// int min(vector<vector<int>> & graph, int r,int c){
//     int a = INT_MAX;
//     if(is_valid(graph, r+1, c)){
//         a = min(a,graph[r][c] - graph[r+1][c]);
//     }
//     if(is_valid(graph, r-1, c)){
//         a = min(a,graph[r][c] -graph[r-1][c]);
//     }
//     if(is_valid(graph, r, c+1)){
//         a = min(a,graph[r][c] -graph[r][c+1]);
//     }
//     if(is_valid(graph, r, c-1)){
//         a = min(a,graph[r][c] -graph[r][c-1]);
//     }
//     return a;
// }

// int Algo(vector<vector<int>> & heights){
//     int res = 0;
//     vector<vector<int>> graphing(heights.size(), vector<int>(heights[0].size(),INT_MAX));

//     graphing[0][0] =heights[0][0];

//     for(int r = 0; r<heights.size();++r){
//         for(int c =0; c<heights[r].size();++c){
//             graphing[r][c] = min(heights,r,c);       
//         }
//     }
//     for(int r = 0; r<heights.size();++r){
//         for(int c =0; c<heights[r].size();++c){
//             cout << graphing[r][c] << " ";       
//         }cout << endl;
//     }

//     return res;
// }

// int main(){

//     vector<vector<int>> heights = {
//         {1,1,1},
//         {3,2,4},
//         {2,5,4}};
//     cout << Algo(heights) << endl;
//     return 0;
// }