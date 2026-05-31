
// #include <iostream>
// #include <vector>

// using namespace std;


// vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    
//     vector<vector<int>> res(heights.size(), vector<int>(heights[0].size(),0));
//     vector<vector<int>> res2(heights.size(), vector<int>(heights[0].size(),0));

//     for(int r = 0; r<heights.size();++r){
//         for(int c = 0; c<heights[r].size();++c){
//             if(r ==0 || c == 0){
//                 res[r][c] +=1;
//             } else{
//                 if(heights[r-1][c] <= heights[r][c] && res[r-1][c] > 0){
//                     res[r][c]+=1;
//                 }
//                 else if(heights[r][c-1] <= heights[r][c] && res[r][c-1] >0){
//                     res[r][c]+=1;
//                 }
//             }
//         }
//     }

//     for(int r = heights.size()-1; r>=0;--r){
//         for(int c = heights[r].size()-1; c>=0;--c){
//             if(r ==heights.size()-1 || c == heights[r].size()-1){
//                 res2[r][c] +=1;
//             }else{
//                 if(heights[r+1][c] <= heights[r][c] && res2[r+1][c]>0){
//                     res2[r][c]+=1;
//                 }
//                 else if(heights[r][c+1] <= heights[r][c] && res2[r][c+1] >0){
//                     res2[r][c]+=1;
//                 }
//             }
//         }
//     }


//     for(int r = heights.size()-1; r>=0;--r){
//         for(int c = heights[r].size()-1; c>=0;--c){
//             res[r][c] += res2[r][c];
//         }
//     }

//     return res;
//     vector<vector<int>> final;

//     for(int r = heights.size()-1; r>=0;--r){
//         for(int c = heights[r].size()-1; c>=0;--c){
//             if(res[r][c] ==2){
//                 final.push_back({r,c});
//             }
//         }
//     }
//     return final;
// }



// int main(){

//     vector<vector<int>> input =
// //   { {4,2,7,3,4},
// //   {7,4,6,4,7},
// //   {6,3,5,3,6}};
// {{1,2,2,3,5},
//  {3,2,3,4,4},
//  {2,4,5,3,1},
//  {6,7,1,4,5},
//  {5,1,1,2,4}};
//     auto res = pacificAtlantic(input);

//     for(auto r : input){
//         for(auto c : r){
//             cout << c << " ";
//         } cout << endl;
//     }
//     cout <<endl;
//     for(auto r : res){
//         for(auto c : r){
//             cout << c << " ";
//         } cout << endl;
//     }

//     return 0;
// }