

#include <iostream>
#include <map>

using namespace std;

string minWindow(string s, string t) {
    if(s.size() < t.size()) return "";
    // if(s.size() == t.size()) return (s==t ? s : "");

    int l=0;
    int r =0;
    string min_res = "";
    
    int n = s.size();

    map<char,int> fingerprint;

    for(int i =0;i<t.size();++i){
        fingerprint[t[i]]--;
    }

    map<char,int> curr_fingerprint;
    string current = "";
    while(r < n){
        if(fingerprint.count(s[r])){
            fingerprint[s[r]]++;
        }
        current += s[r];
        r++;

        while(prod != 0){
            for(auto &[a,b] : fingerprint){
                prod *= b;
            }
            if(prod >= 0) break;

            cout << current << " current min " << min_res;
            min_res = ((min_res.size() > current.size() || min_res.size() == 0) ? current : min_res);
            cout << " after update " << min_res<<endl;

            if(current.size() == 0) break;
            if(fingerprint.count(current[0])){
                fingerprint[current[0]]--;
            }
            current = current.substr(1, current.size() - 1);
        }
    }

    return min_res;

}
int main(){

    cout << minWindow("ADOBECODEBANC", "ABC") << endl;

    return 0;
}