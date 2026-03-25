

#include <iostream>
#include <map>

using namespace std;

bool contains(map<char,int> fingerprint,map<char,int> current){
    for(auto & [a, b]: fingerprint ){
        if(current.count(a)){
            if(b > current[a]){
                return false;
            }
        }else{
            return false;
        }
    }
    return true;
}

string minWindow(string s, string t) {
    if(s.size() < t.size()) return "";
    // if(s.size() == t.size()) return (s==t ? s : "");

    int l=0;
    int r =0;
    string min_res = "";
    
    int n = s.size();

    map<char,int> fingerprint;
    map<char,int> curr_fingerprint;

    for(int i =0;i<t.size();++i){
        fingerprint[t[i]]++;
        curr_fingerprint[t[i]] = 0;
    }

    for(auto & [a,b]: fingerprint){
        cout << a << " "<<b << endl;
    }

    string current = "";
    while(r < n){
        if(fingerprint.count(s[r])){
            curr_fingerprint[s[r]]++;
        }
        current += s[r];
        r++;

        cout << " curr " << current<<endl;
        while(contains(fingerprint, curr_fingerprint)){
            cout << current << " current min " << min_res;
            min_res = ((min_res.size() > current.size() || min_res.size() == 0) ? 
                        current : min_res);
            cout << " after update " << min_res<<endl;

            if(curr_fingerprint.count(current[0])){
                curr_fingerprint[current[0]]--;
                // if(curr_fingerprint[current[0]] == 0){
                //     curr_fingerprint.erase(current[0]);
                // }
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