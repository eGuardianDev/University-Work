

#include <algorithm>
#include <ios>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;;


bool isNStraightHand(vector<int>& hand, int groupSize) {
    

    unordered_map<int, int> maps;
    sort(hand.begin(), hand.end());

    for(int i =0;i<hand.size();++i){
        maps[hand[i]]++;
    }
   

    for(int i =0;i<hand.size();++i){
        if(maps.count(hand[i])){
            int last = hand[i];
            for(int j =0;j<groupSize;++j){
                if(maps.count(last)){
                    maps[last]--;
                    if(maps[last] == 0){
                        maps.erase(last);
                    }
                    last = last+1;
                }else{
                    return false;
                }
            }
        }
    }

    return true;
}


int main(){

    vector<int> list {1,2,4,2,3,5,3,4};
    list = {1,2,3,3,4,5,6,7};
    int groupSize = 4;


    cout << boolalpha << isNStraightHand(list,groupSize) << endl;


    return 0;
}