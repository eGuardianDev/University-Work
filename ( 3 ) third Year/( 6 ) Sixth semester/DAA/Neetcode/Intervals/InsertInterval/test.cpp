
#include <algorithm>
#include <iostream>


class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};
 
#include <vector>

using namespace std;

bool canAttendMeetings(vector<Interval> intervals) {
    sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
        return a.start < b.start;
    });

    for (auto i = 1; i < intervals.size(); ++i) {
        if (intervals[i - 1].end > intervals[i].start)
            return false;
    }

    return true;
}


int main(){

    vector<Interval> intervals;
    intervals.push_back(Interval(5,8));
    intervals.push_back(Interval(9,15));
    
    cout << canAttendMeetings(intervals) << endl;

    return 0;
}