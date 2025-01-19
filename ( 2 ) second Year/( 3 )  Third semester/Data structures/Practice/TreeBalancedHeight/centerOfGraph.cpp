
#include <iostream>
#include <vector>
using namespace std;

int findCenter(vector<vector<int>>& edges) {
    
    vector<int> inward(0);

    for(int i =0;i < edges.size();++i){
        int from = edges[i][0];
        int to = edges[i][1];
        while(from > inward.size() || to > inward.size()){
            inward.push_back(0);
        }
        
        ++inward[from];
        ++inward[to];
    }

    int maxInt =-1;
    int max = -1;

    for(int i =0;i< inward.size();++i){
        if(max < inward[i]){
            max = inward[i];
            maxInt = i;
        }
    }

    return maxInt;
}

int main(){
    vector<vector<int>> a = {{1,2},{2,3},{4,2}};
    vector<vector<int>> b = {{1,2},{5,1},{1,3},{1,4}};
    cout << findCenter(a) << endl;

    return 0;
}