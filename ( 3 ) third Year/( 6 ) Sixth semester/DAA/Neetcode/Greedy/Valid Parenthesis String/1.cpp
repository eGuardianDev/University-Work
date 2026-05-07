#include <ios>
#include <iostream>

using namespace std; 


bool checkValidString(string s) {
  
    int n = s.size();
    int j = n-1;

    int count_star = 0;
    
    int balance = 0;

    for(int i =0;i<n; ++i){
        if(n%2 ==1 && i == (n-1)/2 && s[i]=='*'){
            continue;
        }
    
        if(i < n/2){
            if(s[i] == '*'){
                balance++;
            }
        }else{
            if(s[i]== '*'){
                balance--;
            }
        }
        
        if(s[i]=='('){
            balance++;
        }else if(s[i] == ')'){
            balance--; 
        }

    }

    cout << balance <<endl;




    return balance == 0;
};


int main(){


    cout << boolalpha << checkValidString("((**)")<<endl;

    cout << 5/2;

    return 0;
}