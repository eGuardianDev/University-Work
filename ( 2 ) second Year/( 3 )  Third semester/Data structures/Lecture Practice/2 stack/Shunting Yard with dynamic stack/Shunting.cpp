#include "Stack.hpp"
#include <iostream>
#include <stdexcept>

bool isDigit(char data){
    return (data >= '0' && data <='9' );
}

int getDigit(char data){
    return data-'0';
}

bool isSpace(char data){
    return (data == ' ');
}

bool isOperator(char data){
    switch(data){
        case '+':
        case '-':
        case '*':
        case '/':
            return true;
        default:
            return false;
    }
}

bool isOpenBracket(char data){
    return (data =='(');
}
bool isClosedBracket(char data){
    return (data ==')');
}

int getPriority(char data){
    switch(data){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
            return 0;
    }
    
    return -1;
}

int solve(Stack<int>& numbers, char oper){
    if(numbers.empty()) throw std::logic_error("Invalid syntax");
    int b = numbers.top();numbers.pop();
    if(numbers.empty()) throw std::logic_error("Invalid syntax");
    int a = numbers.top();numbers.pop();
    int res =0;
    switch(oper){
        case '+':
        res =a+b;
        break;
        case '-':
        res = a-b;
        break;
        break;
        case '/':
        res= a/b;
        break;
        case '*':
        res= a*b;
        break;
        break;
    }

    return res;
}

int mathShuntingYand(std::string data){

    std::string toReturn;
    
    Stack<int> numbers;
    Stack<char> symbols;

    int a =0;
    for(char ch : data){
        if(isDigit(ch)){
            a = a*10 + getDigit(ch);
        }
        else{
            if(a>0) {
                numbers.push(a);
                a =0;
                }
            if(isOperator(ch)){

                while(!symbols.empty() && getPriority(symbols.top()) > getPriority(ch) ){
                    numbers.push(solve(numbers,symbols.top()));
                    symbols.pop();
                }
                symbols.push(ch);
            }
            else if(isOpenBracket(ch)){
                symbols.push(ch);
            }else if(isClosedBracket(ch)){
                while(!isOpenBracket(symbols.top()))
                {
                    int result =solve(numbers,symbols.top());
                    numbers.push(result);
                    symbols.pop();
                }
                symbols.pop();
            }

        }
    }
    if(a >0) numbers.push(a);


    while(!symbols.empty()){
        numbers.push(solve(numbers,symbols.top()));
        symbols.pop();
    }

    if(numbers.empty()){
        throw std::logic_error("bad logic");
    }
    int result = numbers.top();
    numbers.pop();
    if(!numbers.empty()){
        throw std::logic_error("bad logic");
    }
    


    return result;

}


int main(){

    std::string data;
    std::getline(std::cin, data );

    std::cout << mathShuntingYand(data);
    return 0;
}