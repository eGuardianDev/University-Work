
#include <climits>
#include <ios>
#include <iostream>
#include <vector>


using namespace std;

bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    
    vector<bool> ignore(triplets.size(), false);
    int false_count = 0;

    for(int j=0;j<triplets.size();++j){
        for(int i =0;i<target.size();++i){
            if(target[i] < triplets[j][i]){
                ignore[j] = true;
                false_count++;
            }
        }
    }

    if(false_count >= triplets.size()) return false;

    vector<int> curr = {INT_MIN, INT_MIN,INT_MIN};
    for(int i =0;i<triplets.size();++i){
        if(ignore[i]) continue;
        curr[0] = max(curr[0],triplets[i][0]);
        curr[1] = max(curr[1],triplets[i][1]);
        curr[2] = max(curr[2],triplets[i][2]);
    }


    
    return curr == target;
    // return true;
}

int main(){


    vector<vector<int>> triplets = {{1,2,3},{7,1,1}};
    vector<int> target = {7,2,3};
    cout << boolalpha << mergeTriplets(triplets, target);


    return 0;
}