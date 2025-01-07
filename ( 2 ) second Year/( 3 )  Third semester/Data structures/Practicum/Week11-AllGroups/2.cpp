#include <iostream>
#include <vector>

using namespace std;

int findJudge(int n, vector<vector<int>>& trust) {
 
    std::vector<int> out1(n);
    std::vector<int> in1(n);
    for(int i = 0; i< trust.size();++i){
            out1[trust[i][0]-1] += 1;
            in1[trust[i][1]-1] += 1;
    }
    
    for(int i =0;i<n;++i){
        if(out1[i] == 0 && in1[i] == n-1){
            return i+1;
        }
    }
    return -1;
}
int main(){

    vector<vector<int>> trust = {{1,3},{1,4},{2,3},{2,4},{4,3}};
    std::cout << findJudge(4,trust);
    return 0;
}