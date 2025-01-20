
#include <string>

#ifndef _Tokens_hpp__
#define _Tokens_hpp__
enum TokenType{

    UNDEFINED = -1,
    //SPECICAL SYMBOLS
    Open_bracket =0, Close_bracket =1,
    Comma =2,
    // DEFINE OPERATION
    LetBe =3, 

    //VARIABLES
    // Name =4,
    Variable = 5, Number =6,
    
    // // generic functions
    // ADD =7, SUB =8 , MUL= 9, DIV= 10, POW= 11, SQRT= 12, SIN= 13, COS= 14, EQ =15, LE=16, NAND=17,

    // //list FUNCTIONS
    // IF=18, LIST=19,HEAD=20,TAIL=21,MAP=22,FILTER=23

};

struct Token{
    TokenType token = UNDEFINED;
    std::string val = "";
};

const std::string TokenToString[] = 
{"(", ")", ",", "<-", "Name", "Var", "Num", "add", "sub", "mul", "div", "pow", "sqrt", "sin", "cos", "eq", "le", "nand","if" ,"list" ,"head" ,"tail" ,"map" ,"filter" 
};

#endif