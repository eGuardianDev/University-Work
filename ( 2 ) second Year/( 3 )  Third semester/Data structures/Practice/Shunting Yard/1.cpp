#include <cmath>
#include <iostream>
#include <stack>
#include <stdexcept>


int priority(char ch){
    switch(ch){
        case '(':
        case ')':
            return 0;
            break;
        case '*':
        case '/':
            return 2;
            break;
        case '+':
        case '-':
            return 1;
        case '^':
            return 4;
            break;
        default : 
            throw std::invalid_argument("This doesn't have a value");
    }
}

bool isNumber(char input){
    return (input >= '0' && input <= '9');
}

bool isOperator(char input){
    switch(input){
        case '*':
        case '/':
        case '+':
        case '-':
        case '^':
        return true;
        default :
        return false;
    }
}

bool isOpenBracket( char input){
    return input == '(';
}
bool isCloseBracket( char input){
    return input == ')';
}


std::string reversePolishNotation(std::string input){

    std::string curr;

    std::stack<char> operators;

    
    for(int i =0;i<input.size();++i){
        if(isNumber(input[i])){
            while(isNumber(input[i])){
                curr +=input[i];
                ++i;
            }
            --i;
            curr +=' ';
        }else if(isOperator(input[i])){
            while(!operators.empty() && priority(operators.top()) >= priority(input[i])){
                curr += (operators.top());
                operators.pop();
            }
            operators.push(input[i]);
        }else if(isOpenBracket(input[i]))
        { 
            operators.push(input[i]);
        }else if(isCloseBracket(input[i])){
            while(!isOpenBracket(operators.top())){
                curr += operators.top();
                operators.pop();
            }
            operators.pop();
        }else if(input[i] == ' '){
        }else{
            throw std::invalid_argument("This is not a number or valid operator");
        }
    }

    while(!operators.empty()){
        curr += (operators.top());
        operators.pop();
    }
    
    return curr;
}


int shuntingYard(std::string input){

    std::stack<double> values;

    for(int i =0;i<input.size();++i){
        if(isNumber(input[i])){
            int val =0;
            while(isNumber(input[i])){
                val *=10;
                val += input[i] - '0';
                ++i;
            }
            values.push(val);
        }else if(isOperator(input[i])){
            double val2 =values.top(); values.pop();
            double val1 = values.top(); values.pop();

            if(input[i] == '+'){
                values.push(val1+val2);
            }else
            if(input[i] == '-'){
                values.push(val1-val2);
            }else
            if(input[i] == '*'){
                values.push(val1*val2);
            }else
            if(input[i] == '/'){
                values.push(val1/val2);
            }
            else
            if(input[i] == '^'){
                values.push(std::pow(val2,val1));
            }

        }
    }  

    if(values.empty()){
        throw std::invalid_argument("problem1");
    }

    double res = values.top(); values.pop();

    if(!values.empty()){
        throw std::invalid_argument("problem2");
    }
    return res;

}


int main(){

    std::string res1 = reversePolishNotation("32+40*2/(10-13)^2^3");
    std::cout << res1 << std::endl << shuntingYard(res1);

    return 0;
}