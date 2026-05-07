

#include <iostream>

#include <vector>

using namespace std;

// vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

//     // bool put = false;
//     // vector<int> toEdit;
//     // for(int i =0;i<intervals.size();++i){
//     //     if(intervals[i][0] < newInterval[0]){
//     //         if(intervals[i][1] < newInterval[0]){
//     //             if(i+1 != intervals.size()){
//     //                 if(intervals[i+1][0] > newInterval[1]){

//     //                 }
//     //             }
//     //         }
//     //         else{
//     //             intervals[i][1] = newInterval[1];
//     //             put = true;
//     //         }
//     //     }
//     // }

//     // if(put){
//     //     for(int i =0 ;i<intervals.size()-1;++i){
//     //         if(intervals[i][1] > intervals[i+1][0]){
//     //             intervals[i][1] = intervals[i+1][1];
//     //             intervals.erase(intervals.begin()+i+1);
//     //         }
//     //     }
//     // }
//     return intervals;
// }
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

    vector<vector<int>> result;

    // for(auto a : intervals){
    //     if(a[1] < newInterval[0]){
    //         result.push_back(a);
    //     }
    // }

    // if(result == intervals){
    //     result.push_back(newInterval);
    //     return result;
    // }
    


    vector<int> curr;
    for(int i =0;i<intervals.size();++i){
        

    }


   
    return result;
}

int main(){

    std::vector<vector<int>> arrays = {{1,3},{4,6}};
    std::vector<int> new_ = {2,5};

    // arrays = {{1,2},{3,5},{9,10}};
    // new_ = {6,7};

    auto a = insert(arrays,new_);

    for(auto b : a){
        cout << "[ " << b[0] << " : " << b[1] << " ] ";
    }cout<<endl;

    return 0; 
}