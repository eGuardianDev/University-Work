

#ifndef _Tokens_hpp__
#define _Tokens_hpp__

#include <string>

enum TokenType{

    UNDEFINED = -1,
    //SPECICAL SYMBOLS
    Open_bracket =0, Close_bracket =1,
    Comma =2,
    // DEFINE OPERATION
    LetBe =3, 

    //VARIABLES
    Function =4,
    Variable = 5, Number =6,
};

struct Token{
    TokenType token = UNDEFINED;
    std::string val = "";
};



#endif