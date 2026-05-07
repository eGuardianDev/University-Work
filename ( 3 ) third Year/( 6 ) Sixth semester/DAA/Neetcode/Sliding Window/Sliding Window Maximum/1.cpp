#include <climits>
#include <iostream>
#include <vector>


using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    std::vector<int> res;

    int l =0;
    int r =0;

    int n = nums.size();
 

    int c_max= 0;

    while(r < k){
        c_max = max(c_max, nums[r]);
        r++;
    }
    res.push_back(c_max);

    // res.push_back(c_max);

    while(r < n){
        l++;
        r++;
        int m_max = INT_MIN;
        for(int i =l;i<r;++i){
            m_max = max(m_max, nums[i]);
        }
        res.push_back(m_max);
    }



    return res;
    
}

int main(){


    vector<int> v = {1,2,1,0,4,2,6};

    // v = {1,-1};
    auto data = maxSlidingWindow(v, 3);

    for(auto info : data){
        cout << info<< " ";
    } cout << endl;


    return 0;
}