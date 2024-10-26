#include <iostream>
#include <stack>

int scoreOfParentheses(std::string s) {

    std::stack<int> stack;
    int current =0;
    int last =0;
    for(int i =0 ;i<s.size();i++){
        switch(s[i]){
            case '(':
                stack.push(last);
                last = 0;
            break;
            case ')':
                // last = stack.top() + std::max(2  *last, 1);
                current = stack.top();
                stack.pop();
                if(last != 0) last *=2;
                else last = 1;
                last += current; 
            break;
        }
    }  
    return last;
}

int main(){

    std::string n;
    std::cin >> n;

    std::cout << scoreOfParentheses(n) << std::endl;
    
    return 0;
}