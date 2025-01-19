#include <exception>
#include <iostream>
#include <stack>
#include <stdexcept>
#include <vector>
// #include "Checker.hpp"
#include "Objects.hpp"
#include "Reader.hpp"
#include "SyntaxTreeBuilder.hpp"

std::string a = "";
std::stack<Object*> programStack;

void printToken(Token token){
    std::cout << TokenToString[token.token];
}
void printTokenVal(Token token){
    std::cout << token.val;
}
// std::string printToken(Tokens token){
//     switch(token){
//         case Open_bracket:
//         return  "(";
//         case Close_bracket:
//         return  ")";
//         case Comma:
//         return  ",";
//         case LetBe:
//         return  "<-";
//         case Name:
//         return  "Name";
//         case Variable:
//         return  "Var";
//         case Number:
//         return  "Num";
//         case ADD:
//         return  "add";
//         case SUB:
//         return  "sub";
//         case MUL:
//         return  "mul";
//         case DIV:
//         return  "div";
//         case POW:
//         return  "pow";
//         case SQRT:
//         return  "sqrt";
//         case SIN:
//         return  "sin";
//         case COS:
//         return  "cos";
//         case EQ:
//         return  "eq";
//         case LE:
//         return  "le";
//         case NAND:
//         return  "nand";
//         case IF:
//         return "if"; 
//         case LIST:
//         return "list"; 
//         case HEAD:
//         return "head"; 
//         case TAIL:
//         return "tail"; 
//         case MAP:
//         return "map"; 
//         case FILTER:
//         return "filter"; 

//     }
// }

void CLI(){
    std::string cmd;
    while(getline(std::cin, cmd)){
        Reader r;
        
        try{
            r.Read(cmd);
        }catch(std::invalid_argument e){
            std::cout << "| Error | " << e.what() << "\n";
        }

        for(auto a : r.getTokens()){
            printToken(a);
        }
        std::cout << "\n";
        for(auto a : r.getTokens()){
            printTokenVal(a);
        }
        std::cout << "\n";

        try{
            STBuilder builder;
            std::vector<Token> tokens = r.getTokens();
            builder.build(tokens);
        }catch( const char* e){
            std::cout << "ERORR | " << e <<std::endl; 
        }

        // Checker ch;
        
        // ch.Check(types);
        std::cout <<  '\n';
    }
}


int main(){
    CLI();
  
    return 0;
}