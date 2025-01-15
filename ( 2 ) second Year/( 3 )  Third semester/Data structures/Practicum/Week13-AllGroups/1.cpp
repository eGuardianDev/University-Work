
#include <iostream>
#include <unordered_map>
#include <vector>

int findLHS(std::vector<int>& nums) {
        
    std::unordered_map<int,int> map;
    for(const int& n : nums){
        if(map.count(n) == 0){
            map[n] = 0;
        }
        ++map[n];
    }

    int max =0;
    for(auto i = map.begin(); i != map.end();++i ){

        if(map.count(i->first) && map.count(i->first+1)){
            int temp = i->second + (map[i->first+1]); 
            if(temp > max){
                max = temp;
            }
        }

    }

    return max;
}

int main(){

    std::vector<int> nums = {-1,0,-1,0,-1,0,-1};

    std::cout << findLHS(nums) << '\n';


    return 0;
}