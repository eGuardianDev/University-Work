#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int res = 0;

    sort(intervals.begin(), intervals.end(),
        [](const vector<int>& x, const vector<int>& y) {
            if(x[0] == y[0]){
                return x[1] < y[1];
            }
            return x[0] < y[0];      // primary: second
            // return abs(x[1]-x[0]) < abs(y[1] -y[0]);
        }
    );

    for(auto a : intervals){
        cout << "[" << a[0] << ":" << a[1] << "] ";
    }cout <<endl;


    auto last = intervals[0];

    int last_end = intervals[0][1];
    int n =intervals.size();
    for(int i = 1; i<n ;++i){
        if(intervals[i][0] < last_end){
            res++;
        }else last_end = intervals[i][1];
    }



    return res;
}
int main(){
    vector<vector<int>> a = {{1,2},{2,4},{1,4}};

    // a = {{1,100},{11,22},{1,11},{2,12}};
    // a = {{-52,31},{-73,-26},{82,97},{-65,-11},{-62,-49},{95,99},{58,95},{-31,49},{66,98},{-63,2},{30,47},{-40,-26}};
    cout << eraseOverlapIntervals(a) << endl;

    return 0;
}