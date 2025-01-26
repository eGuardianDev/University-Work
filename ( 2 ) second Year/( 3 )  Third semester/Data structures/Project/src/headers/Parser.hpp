
#ifndef _Parser_hpp__
#define _Parser_hpp__

#include "Expression.hpp"
#include <stdexcept>
#include <string>
#include <vector>
#include "Tokens.hpp"

class Parser{

private:
    Token &Peak();
    Token &Pop();
    bool end();
    void next();
    void reset();
    
    void problem(const std::string& data);

    void Clean();

public:   
    Parser(){}
    ~Parser(){}
    Parser(Parser&)  = delete;
    Parser& operator=(Parser&) = delete;
    Parser(Parser&&)  = delete;
    Parser& operator=(Parser&&) = delete;


    Expression* build(std::vector<Token> _objs, int& _index);
    Expression* build(std::vector<Token> _objs);

private:

    std::vector<Token> objs;

    int maxArgumnets = 0;
    int index = 0;
    bool afterLet = false;
};

#endif //_Parser_hpp__