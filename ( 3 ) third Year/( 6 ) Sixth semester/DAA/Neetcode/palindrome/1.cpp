

#include <iostream>

using namespace std;
    bool isPalindrome(string s) {

        string new_s;

        for(int i =0;i<s.size();++i){
            if((s[i] >= 'A' &&  s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') ){
                new_s += (char)tolower(s[i]);
            }  
        }

        for(int i =0;i<new_s.size();++i){
            if(new_s[i] >= 'A' && new_s[i] <= 'Z' ){
                new_s[i] = (char)tolower(new_s[i]);
            }  
        }
        s = new_s;
        cout << s;
        int l = 0, r = s.size()-1;

        while(l <r){
            if(s[l] == s[r]){
                l++;r--;
            }else return false;

        }
        return true;
    }
int main(){

    string s = "Was it a car or a cat I saw?";
    cout << isPalindrome(s) << endl;
    return 0;
}