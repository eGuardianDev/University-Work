#include <iostream>
#include <stack>


int main(){

    std::string input;
    std::cin >> input;

    std::string array;
    
    std::stack<int> stack;
    std::string current;
    for(int i =0; i<input.size();i++){
    
        switch(input[i]){
            case '[':
            stack.push(input[i-1]);
            case ']':
            
        }
        
    }
    

    return 0;
}