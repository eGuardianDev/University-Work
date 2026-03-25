#include <iostream>
#include <map>

using namespace std;

bool checkInclusion(string s1, string s2) {
    map<char, int> perm;

    int size_perm =0;
    for(auto c :s1){
        perm[c]++;
        size_perm++;
    }

    int size = 0;
    map<char, int> perm2;
    int l=0;
    int r=0;
    int n =s2.size();
    
    while(r <= n){
        if(perm2 == perm){
            return true;
        }

        if(size <= size_perm){
            perm2[s2[r]]++;
            r++;
            size++;

        }else{
            perm2[s2[l]]--;
            size--;
            
            if (perm2[s2[l]] == 0) {
                perm2.erase(s2[l]);
            }
            l++;    
        }

    }
    return false;
}



int main(){

    cout << boolalpha << checkInclusion("abc","lcba") << endl;
    return 0;
}