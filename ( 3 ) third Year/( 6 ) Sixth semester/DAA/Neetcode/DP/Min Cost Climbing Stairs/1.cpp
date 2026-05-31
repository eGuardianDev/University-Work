#include <algorithm>
#include <functional>
#include <iostream>

#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int,int> mem;

int helper(vector<int> & cost, int point){
    if(point >= cost.size()) return 0;

    if(mem.count(point)) return mem[point];
    
    mem[point] = cost[point] + min(helper(cost,point+1), helper(cost,point+2));
    return mem[point];
}

int minCostClimbingStairs(vector<int>& cost) {
    return min(helper(cost,0), helper(cost,1));
}

int main(){

    // vector<int> in = {1,2,3};
    vector<int> in = {1,2,1,2,1,1,1};


    cout << minCostClimbingStairs(in) << endl;
    return 0;
}