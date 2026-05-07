#include <algorithm>
#include <iostream>
#include <vector>

 class Interval {
  public:
      int start, end;
      Interval(int start, int end) {
          this->start = start;
          this->end = end;
      }
};

using namespace std;
int minMeetingRooms(vector<Interval>& intervals) {
        
    sort(intervals.begin(), intervals.end(),
    [](Interval& x, Interval& y) {
        return x.end > y.end;      // primary: end DESC
    }
    );

    for(auto i : intervals){
        cout << "["<< i.start << " : "<< i.end << "] ";
    }cout<<endl;

    
    return 0;
}


int main(){

    vector<Interval> inter = { Interval(0,40),Interval(5,10),Interval(15,20)};

    cout << minMeetingRooms(inter) << endl;

    return 0;
}