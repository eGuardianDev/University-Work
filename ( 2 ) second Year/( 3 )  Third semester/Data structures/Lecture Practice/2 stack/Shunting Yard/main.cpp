#include <iostream>
#include <queue>
#include <stack>
#include <stdexcept>
#include <string>

int getPriority(const char& character){
    switch(character){
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        case '(':
        case ')':
            return 0;
        default:
            return -1; //number
    }
}
bool isOpeningBracket(const char& bracket){
    switch(bracket){
        case '(':
        return true;
        case ')':
        return false;
    }
    return false;
}
char getReversedBracket(const char& bracket){
    switch(bracket){
        case ')':
        return '(';
        case '(':
        return ')';
    }
    return '-'; // invalid symbol
}

std::string ReversePolishNotation(const std::string& input){
    if(input.size() < 3){
        throw std::invalid_argument("input too small to do any operations");
    }
    std::string output;

    std::stack<char> operators;
    std::queue<char> symbols;

    for(size_t i = 0; i< input.size(); ++i){
        char cur = input[i];
        switch(getPriority(cur)){
            case 2: // / *
                operators.push(cur);    

            break;
            case 1: // + -
                while(!operators.empty() && 
                getPriority(operators.top()) > getPriority(cur))
                {
                    symbols.push(operators.top());
                    operators.pop();
                }
                operators.push(cur);

            break;
            case 0: // ( )
                if(isOpeningBracket(cur)){
                    operators.push(cur);
                }else{
                    while(!operators.empty() && operators.top() != getReversedBracket(cur)){
                        symbols.push(operators.top());
                        operators.pop();
                    }
                    if(operators.empty()){
                        throw std::invalid_argument("Didn't find closing bracket");
                    }
                    operators.pop();
                }
            break;
            case -1: // numbers
               
                symbols.push(cur);

                
            break;
        }

    }
    while(!symbols.empty())
    {
        output += symbols.front();
        symbols.pop();   
    }
    while(!operators.empty()){
        if(getPriority(operators.top()) == 0)
        { operators.pop(); continue; } // ingores opened brackets
        output += operators.top();
        operators.pop();
    }

    return output;
}

int ShuntingYardCalculator(const std::string& input){
    if(input.size() < 3){
        throw std::invalid_argument("input too small to do any operations");
    }
    std::stack<int> stack;
    for(size_t i = 0;i<input.size();++i){
        char cur = input[i];
        if(getPriority(cur) >0){
            int val2 = stack.top(); stack.pop();
            int val1 = stack.top(); stack.pop();
            int result;
            switch(cur){
                case '*':
                result = val1 * val2;
                break;
                case '/':
                if(val2 == 0) throw std::runtime_error("devides by zero");
                result = val1 / val2;
                break;
                case '+':
                result = val1 + val2;
                break;
                case '-':
                result = val1 - val2;
                break;
            }
            stack.push(result);
        }else{
            stack.push((int)cur - 48);
        }
    }
    if(stack.empty()){
        throw std::invalid_argument("Too many symbols?");
    }
    return stack.top();
}




int main(){
        // only works with single digits
        // has brackets, +, -, *, /
        // needs correct input like "1+(2*3)"
        // things like "2+3(-1" break it. ( ! added fix for ignoreing brackes)
    
    std::string command;

    std::getline(std::cin, command);
    
    std::string notation =ReversePolishNotation(command);
    std::cout << "Reverse Polish Notation: "<<notation << "\n";
    std::cout << "Answear:" << ShuntingYardCalculator(notation) << '\n';

    return 0;
}