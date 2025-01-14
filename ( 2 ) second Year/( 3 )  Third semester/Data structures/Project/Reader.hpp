
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Tokens.hpp"
class Reader{

    std::string data;
    int index =0;
    std::vector<TokenType> tokens;

    bool isEnd(){return index == data.size();}
    char &Peak(){
         return data[index]; }
    void Next(){ ++index; }
    char &Pop(){ return data[index++];}
    char &Last() {
        if(index-1 < 0){
            throw std::logic_error("Trying to go back, but underflow");
        }
         return data[index-1];} 

    void invalidChar(char &data, int position){
        this->tokens.clear();
        std::string res = "Invalid character in string \n" + std::string(2, ' ') + this->data+'\n'+std::string(position+2, ' ') + "^-- here\n";

        throw std::invalid_argument(res);
    }

    bool isDigit(char &data){
        return data >= '0' && data <='9';
    }

    bool isAlpha(char &data){
        return (data >= 'a' && data <= 'z') || (data >='A' && data <= 'Z');
    }

    public:
    Reader(){}
    ~Reader(){}

    void Read(std::string input){
        this->data = input;
        index = 0;

        while(!isEnd()){
            switch(Pop()){
                case ' ':
                //ignore
                break;
                case '<':
                    if(!isEnd() && Peak() == '-'){
                        tokens.push_back(LetBe);
                        Next();
                    }
                    else{
                        invalidChar(Peak(),index);
                    }
                break;

                case '(':
                    tokens.push_back(Open_bracket);
                break;
                case ')':
                    tokens.push_back(Close_bracket);
                break;
                case ',':
                    tokens.push_back(Comma);
                break;
                case '#':
                    tokens.push_back(Variable);
                    while(!isEnd() && isDigit(Peak())){
                        Next();
                    }
                    if(Peak() != ',' && Peak() != ')'){
                        invalidChar(Peak(),index);
                    }
                break;
                default:
                char last = Last();
                std::string tempData;
                if(last == '-' || isDigit(last)){
                    tempData +=last;
                    while(isDigit(last = Peak())){
                        tempData +=last;
                        //add to something
                        Next();
                    }
                    if(isAlpha(Peak())){
                        invalidChar(Peak(),index);
                    }
                    tokens.push_back(Number);
                }else if(isAlpha(last)){
                    tempData +=last;
                    while(isAlpha(last = Peak())){
                        tempData +=last;
                        //add to something
                        Next();
                    }
                    if(isDigit(Peak())){
                        invalidChar(Peak(),index);
                    }
                    if (tempData == "add") {
                        tokens.push_back(ADD);
                    } else if (tempData == "sub") {
                        tokens.push_back(SUB);
                    } else if (tempData == "mul") {
                        tokens.push_back(MUL);
                    } else if (tempData == "div") {
                        tokens.push_back(DIV);
                    } else if (tempData == "pow") {
                        tokens.push_back(POW);
                    } else if (tempData == "sqrt") {
                        tokens.push_back(SQRT);
                    } else if (tempData == "sin") {
                        tokens.push_back(SIN);
                    } else if (tempData == "cos") {
                        tokens.push_back(COS);
                    } else if (tempData == "eq") {
                        tokens.push_back(EQ);
                    } else if (tempData == "le") {
                        tokens.push_back(LE);
                    } else if (tempData == "nand") {
                        tokens.push_back(NAND);
                    } else if (tempData == "if") {
                        tokens.push_back(IF);
                    } else if (tempData == "list") {
                        tokens.push_back(LIST);
                    } else if (tempData == "head") {
                        tokens.push_back(HEAD);
                    } else if (tempData == "tail") {
                        tokens.push_back(TAIL);
                    } else if (tempData == "map") {
                        tokens.push_back(MAP);
                    } else if (tempData == "filter") {
                        tokens.push_back(FILTER);
                    }else{
                        tokens.push_back(Variable);
                    }
                }else{
                    invalidChar(last, index-1);
                }
                break;
            }
        }
    }

    const std::vector<TokenType>& getTokens(){
        return this->tokens;
    }

};
