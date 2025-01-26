
#ifndef _Lexer_hpp__
#define _Lexer_hpp__

#include <stdexcept>
#include <vector>
#include "Tokens.hpp"
class Lexer{

    std::string data;
    int index =0;
    std::vector<Token> tokens;

    bool isEnd();
    char &Peak();
    void Next();
    char &Pop();
    char &Last();

    void invalidChar(const char &data, const int position);

    bool isDigit(const char &data) const;

    bool isAlpha(const char &data)const;
  
    public:
    Lexer(){}
    ~Lexer(){}
    Lexer(Lexer&)  = delete;
    Lexer& operator=(Lexer&) = delete;
    Lexer(Lexer&&)  = delete;
    Lexer& operator=(Lexer&&) = delete;

    void Clear();
    void Read(std::string input);

    const std::vector<Token>& getTokens();

};

#endif //_Lexer_hpp__
