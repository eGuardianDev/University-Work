
#include <iostream>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int l = 0;
    int r = 0;
    
    unordered_map<char, int> table;

    int n = s.size();
    int max_size = 0;

    while(r < n){
        char c = s[r];
        if(table[c] == 0){
            r++;
            table[c]++;
        }else{
            table[s[l]]--;
            l++;
        }
        max_size = max(r-l, max_size);
    }

    return max_size;
}
int main(){

    string s = "zxyzxyz";

    cout << lengthOfLongestSubstring(s) << endl;

    return 0;
}