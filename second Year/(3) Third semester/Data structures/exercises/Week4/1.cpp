#include <ios>
#include <iostream>
#include <stack>
#include <stdexcept>

using BraceType = bool;

BraceType getBraceType(const char c){
    switch(c){
        case '{':
        case '}':return 0;
        case '(':
        case ')':return 1;
        default: throw std::runtime_error("Argument is not a brace");
    }
}
bool isOpenBrace(const char c){
    return c == '(' || c == '{';
}

bool isClosingBrace(char c) {
    return c == ')' || c == '}';
}


bool checkBraces(const std::string & str){

    std::stack<BraceType> stack;
    for(char c : str){
        /*
        switch(c)
        {     //old style
            case '(':
                stack.push(0);
                break;
            case '}':
                if(!stack.empty() && stack.top()==1 ) stack.pop();
                else return false;
                break;
        }
        */
        if(isOpenBrace(c)){
            stack.push(getBraceType(c));
        }else if(isClosingBrace(c)){
            if(!stack.empty() && stack.top() == getBraceType(c))
            stack.pop();
        }
    }
    return stack.empty();
}


int main(){
    //boolalpha = > true/false insted of 1/0
    std::cout << std::boolalpha << checkBraces("{({})}") << " ";
    std::cout << std::boolalpha << checkBraces("{({)}");

    return 0;
}