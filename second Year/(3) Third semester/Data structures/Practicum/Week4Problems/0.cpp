#include <iostream>
#include <stack>




int main(){
    std::stack<char> brackets;
    std::string data;
    std::cin >> data;
    bool errorFlag = false;
    for(int i =0 ;i<data.size();i++){
        char c = data[i];
        switch((c)){
            case '[':
            case '{':
            case '(':
                brackets.push(c);
                break;
            case ']':
                if(brackets.size() >0 && brackets.top() == '[') brackets.pop();
                else errorFlag = true;
                break;
            case '}':
                if(brackets.size() >0 && brackets.top() == '{') brackets.pop();
                else errorFlag = true;
                break;
            case ')':
                if(brackets.size() >0 && brackets.top() == '(') brackets.pop();
                else errorFlag = true;
                break;
        }
        if(errorFlag) 
        {
            std::cout << "Brackets are bad \n";
            return 1;
        }
    }
    if(!errorFlag){
        std::cout << "brackets are fine";
    }
    return 0;
}