
#ifndef _Lexer_hpp__
#define _Lexer_hpp__

#include <stdexcept>
#include <vector>
#include "Tokens.hpp"
class Lexer{

    std::string data;
    int index =0;
    std::vector<Token> tokens;

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

    void invalidChar(const char &data, const int position){
        this->tokens.clear();
        std::string res = "Invalid character in string \n" + std::string(2, ' ') + this->data+'\n'+std::string(position+2, ' ') + "^-- here\n";

        throw std::invalid_argument(res);
    }

    bool isDigit(const char &data) const{
        return data >= '0' && data <='9';
    }

    bool isAlpha(const char &data)const{
        return (data >= 'a' && data <= 'z') || (data >='A' && data <= 'Z');
    }
  
    public:
    Lexer(){}
    ~Lexer(){}
    Lexer(Lexer&)  = delete;
    Lexer& operator=(Lexer&) = delete;
    Lexer(Lexer&&)  = delete;
    Lexer& operator=(Lexer&&) = delete;

    void Clear(){
        tokens.clear();
        index = 0;
    }
    void Read(std::string input){
        Clear();
        this->data = input;
        index = 0;
        while(!isEnd()){
            switch(Pop()){
                case ' ':
                //ignore
                break;
                case '<':
                    if(!isEnd() && Peak() == '-'){
                        tokens.push_back({LetBe, "<-"});
                        Next();
                    }
                    else{
                        invalidChar(Peak(),index);
                    }
                break;

                case '(':
                    tokens.push_back({Open_bracket, "("});
                break;
                case ')':
                    tokens.push_back({Close_bracket, ")"});
                break;
                case ',':
                    tokens.push_back({Comma, ","});
                break;
                case '#':
                    {
                        std::string val = "#";
                        Token temp {Variable};
                        while(!isEnd() && isDigit(Peak())){
                            val += Peak();
                            Next();
                        }
                        temp.val = val;
                        tokens.push_back(temp);
                    }
                    break;
                default:
                char last = Last();
                std::string currData;
                if(last == '-' || isDigit(last)){
                    currData +=last;
                    int dots = 0;
                    while((last = Peak()) && (last == '.' || isDigit(last))){
                        if(last == '.'){
                            dots++;
                        }
                        if(dots >1) break;
                        currData +=last;
                        Next();
                    }
                    //after check
                    if(Peak() == '-'){
                        invalidChar(Peak(),index);
                    }
                    if(dots > 1){
                        invalidChar(Peak(),index);
                    }
                    if(isAlpha(Peak())){
                        invalidChar(Peak(),index);
                    }
                    if(currData.length() > 0 && currData[currData.length()-1] == '.'){
                        invalidChar(Peak(),index);
                    }

                    tokens.push_back({Number,currData});
                }else if(isAlpha(last)){
                    currData += last;
                    while(isAlpha(last = Peak()) || isDigit(last =Peak())){
                        currData += last;
                        Next();
                    }

                    //aftercheck
                    if((last=Peak())=='#'){
                        invalidChar(Peak(),index);
                    }
                    tokens.push_back({Function,currData});
                }else{
                    invalidChar(Peak(),index-1);
                }
                break;
            }
        }
    }

    const std::vector<Token>& getTokens(){
        return this->tokens;
    }

};

#endif //_Lexer_hpp__
