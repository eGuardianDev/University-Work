
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int mostBooked(int n, vector<vector<int>>& meetings) {
        

    sort(meetings.begin(), meetings.end(),
        [](vector<int>& a, vector<int>& b){
            if(a[0]==b[0]){
                return a[1] < b[1];
            }
            return a[0] < b[0]; 
        });

    vector<bool> rooms(n, false);
    vector<int>  finish(n, 0);

    int m = meetings.size();
    int empty = n;
    int i =0;

    while(i<m){
        int start = meetings[i][0];
        int end = meetings[i][1];

        bool flag = false; // assigned
        int wait = INT_MAX;
        for(int j=0;j<rooms.size();++j){
            if(rooms[j] == false){
                flag = true; 
                finish[j] = end;
                break;
            }else{
                wait = min(wait, finish[j]);
            }
        }
        
        if(flag == false){
            meetings[i][0] = 
        }else{
            i++;
        }

    }

}

int main(){

    int n =2;
    vector<vector<int>> meetings =  {{1,10},{2,10},{3,10},{4,10}};


    cout << mostBooked(n, meetings) << endl;


    return 0;
}