#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    int removeDuplicates(vector<int>& nums) {
         int count = 1;
        int selected = nums[0];
           for(int i =1;i <nums.size(); i++){
            if(selected != nums[i]){
                selected = nums[i];
                count = 1;
            }else{
                count++;
                if(count >2){
                    nums.erase(nums.begin()+i);
                    i--;
                }
            }

        }
        return nums.size();
    }
};


int main(){

    std::cout <<"hello world";
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(2);
    vec.push_back(3);
    
    return 0;
}