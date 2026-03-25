#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int l, int target){
    // int l =0;
    int r = numbers.size()-1;

    int sum;
    while(l <r && target != (sum = numbers[l] + numbers[r])){
        if(sum < target) l++;
        if(sum > target) r--;
    }

    if(l >= r) return {};
    vector<int> res;
    res.push_back(l);
    res.push_back(r);

    return res;
}


vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> results;

    
    sort(nums.begin(), nums.end());
    for(int i =0;i<nums.size();++i){
        vector<int> res;
        
        vector<int> a;
        for(int j = i+1;j<nums.size();++j){
            res.clear();
            res.push_back(nums[i]);
            a =(twoSum(nums, j, -nums[i]));
            
            for(auto b:a){
                res.push_back(nums[b]);
            }
            
            if(res.size() > 1){
                
            if(std::find(results.begin(), results.end(), res) != results.end()) {
                continue;
            } 
                results.push_back(res);
            }
        }
    }
    
    return results;
}

int main(){


    // vector<int> arr = {-1,0,1,2,-1,-4};
    vector<int> arr = {-2,0,1,1,2};

    for(auto a : threeSum(arr)){
        cout << a.size() << " works with : ";
        for(auto b : a){
            cout << b << " ";
        }
        cout << endl;
    }

    return 0;
}