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



bool canTraverseAllPairs(vector<int>& nums) {
    

    // vector<vector<int>> graph(nums.size());
    vector<vector<int>> graph(nums.size(), vector<int>(nums.size(), INT_MAX));

    for(int i =0;i<nums.size();++i){
        for(int j =i+1;j<nums.size();++j){
            if(gcd(nums[i],nums[j])>1){
                graph[i][j] = 1;
                graph[j][i] = 1;
            }        
        }
    }
    for(int i =0;i<nums.size();++i){
        graph[i][i] = 0;
    }

    int n = graph.size();
    for(int k =0;k<n;++k){
        for(int i =0 ;i<n;++i){
                for(int j = 0;j<n;++j){
                if(graph[i][k] != INT_MAX && graph[k][j]!= INT_MAX )
                    graph[i][j] = min(graph[i][j],
                                     graph[i][k] + graph[k][j]);
            }
        }
    }


    for(int i =0;i<graph.size();++i){
        for(int j =0;j<graph.size();++j){
            cout << graph[i][j] << " ";
        } cout <<endl;
    }


    for(int i =0;i<graph.size();++i){
        for(int j =i+1; j<graph.size();++j){
            if(graph[i][j] == INT_MAX) return false;
    // if(count == nChoosek(nums.size(),2)) return true;
        }
    }
    return true;
}

int main(){
    
    vector<int> nums = {4,3,12};

    cout << canTraverseAllPairs(nums) << endl;

    return 0;
}