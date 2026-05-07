#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    
    vector<vector<int>> result;

    
    sort(intervals.begin(), intervals.end(),
    [](const vector<int>& x, const vector<int>& y) {
        return x[0] < y[0];
        }
    );

    // result.push_back({intervals[0][0],intervals[0][1]});

    vector<int> last = intervals[0];

    int n =intervals.size();
    for(int i =1;i<n;++i){
        // cout << "i " <<last[0] <<"< " << intervals[i][0] << "<" << last[1] << endl;
        if(last[0] <= intervals[i][0] && intervals[i][0] <= last[1]){
            last[1] = intervals[i][1];
        }else{
            result.push_back(last);
            last = intervals[i];
        }
    }
    result.push_back(last);

    


    return result;
}

int main(){

    vector<vector<int>> a = {{1,3},{1,5},{6,7}};

    // a = {{1,2},{2,3}};
    auto res = merge(a);

    for(auto r : res){
        cout << " ["<< r[0] << " : " << r[1] << "] ";
    }cout <<endl;

    return 0;
}