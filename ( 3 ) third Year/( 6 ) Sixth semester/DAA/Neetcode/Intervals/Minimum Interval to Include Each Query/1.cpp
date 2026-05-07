
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;


vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {

    for(int i =0;i<intervals.size();++i){
        // intervals[i].push_back(i);
        int a = intervals[i][0];
        int b = intervals[i][1];
        intervals[i].push_back(b-a+1);
    }

    // sort(intervals.begin(),intervals.end(),
    //     [](const vector<int>& a, const vector<int>& b) {
    //         return a[3] < b[3];}
    // );

    vector<int> res(queries.size(), INT_MAX);

    for(int i =0;i<queries.size();++i){
        for(int j =0;j<intervals.size();++j){
            if(intervals[j][0] <= queries[i] && queries[i] <= intervals[j][1]){
                res[i] = min(res[i],intervals[j][2]);
            }
        }
    }

    for(int i =0;i<res.size();++i){
        if(res[i] == INT_MAX) res[i] = -1;
    }

    return res;
}

int main(){

    vector<vector<int>> intervals = {{1,3},{2,3},{3,7},{6,6}};
    vector<int> queries = {2,3,1,7,6,8};

    auto res = minInterval(intervals,queries);

    for(auto a : res){
        cout << a << " "; 
    }cout << endl;


    return 0;
}
