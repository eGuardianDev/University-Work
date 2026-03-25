
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;


char biggest(unordered_map<char, int> &map){

    char biggest =0;
    int value = 0;
    for(auto [a,b] : map){
        if(b > value){
            biggest = a;
            value = b;
        }
    }

    return biggest;
}

int characterReplacement(string s, int k) {

    int l = 0;
    int r = 0;
    int n = s.size();


    int max_size = 0;
    unordered_map<char, int> map;
    
    int curr = 0;
    while(r < n){
        char c = s[r];
        map[c]++;
        curr++;
        r++;

        if(curr <= k){
            max_size = max(curr, max_size);
        }else{
            char big = biggest(map);
            if(curr - map[big] <= k){
                max_size = max(curr, max_size);
            }else{
                map[s[l]]--;
                l++;
                curr--;
            }
        }

    }
    
    return max_size;
}

int main(){

    cout << characterReplacement("ABAA", 0) << endl ;

    return 0;
}