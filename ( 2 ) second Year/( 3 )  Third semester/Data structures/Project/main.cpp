#include <exception>
#include <iostream>
#include <stack>
#include <stdexcept>
#include <unordered_map>
#include <vector>
// #include "Checker.hpp"
#include "Evaluator.hpp"
#include "Expression.hpp"
// #include "Objects.hpp"
#include "Lexer.hpp"
#include "Parser.hpp"
#include "tokenChecker.hpp"
#include <fstream>
#define Debug_mode

// std::string a = "";
// std::stack<Object*> programStack;

#ifdef Debug_mode
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
#endif

void runCmd(std::string data);
void ReadFromFile(){
    std::fstream File("input.txt");

    std::string cmd;
    while(std::getline(File, cmd)){
        runCmd(cmd);
    }
}

void CLI(){
    std::string cmd;

    while(true){
        std::cout << "# ";
        getline(std::cin, cmd);

        if(cmd == ""){
            continue;
        }
        if(cmd == "end"){
            break;
        }
        runCmd(cmd);
    }
}

std::unordered_multimap<std::string, executeArgs> functions;
void clean(){
     for(auto it = functions.begin(); it != functions.end();){
        it->second.function->Destruct();
        it++;
    }
}

void runCmd(std::string cmd){

   
    // functions.insert({"add",{2, [](std::vector<Expression*> args) -> Expression*
    // {  
    // }}});
    

        Parser builder;
        
        
        // std::cout << cmd;
        Reader r;
        try{
            r.Read(cmd);
        }catch(std::invalid_argument e){
            std::cout << "| Error | " << e.what() << "\n";
        }

        // for(auto a : r.getTokens()){
        //     printToken(a);
            
        // }
        // std::cout << "\n";
        // for(auto a : r.getTokens()){
        //     printTokenVal(a);
            
        // }
        // std::cout << "\n";

        std::vector<Token> tokens = r.getTokens();

        if(tokens.size() ==0){
            return;
        }

        try{
            // std::cout << "Begin checking" << std::endl;
            tokenChecker checker;
            checker.check(tokens);
        }catch(std::runtime_error& e){
            std::cout << "\nERORR | " << e.what() <<std::endl;
            return; 
        }

      

        Expression *currFunct = nullptr;
        try{
            // std::cout << "Begin building" << std::endl;
            currFunct = builder.build(tokens);
        }catch( std::runtime_error& e){
            std::cout << "\nERORR | " << e.what() <<std::endl; 
            if(currFunct) currFunct->Destruct();
            currFunct = nullptr;
            return;
        }

        // currFunct->print(std::cout);


        try{
            std::vector<Expression*> env(0);
            Evaluator eval(currFunct,functions, env);
            Expression* res = eval.evaluate();
                      
            if (Number_Exp* curr = dynamic_cast<Number_Exp*>(res); curr != nullptr){
                curr->print(std::cout);
                std::cout << std::endl;
            } else if (Associate_Exp* curr = dynamic_cast<Associate_Exp*>(res); curr != nullptr){
                // delete curr;
                // res->Destruct();
                delete res;
                return;
            } else if (List_Exp* curr = dynamic_cast<List_Exp*>(res); curr != nullptr){
                // delete curr;
                // res->Destruct();
                // delete res;
                std::cout << "[";
                curr->print(std::cout);
                std::cout << "]" << std::endl;
                // continue;
            }else
            {
                throw std::runtime_error("Evaluation failed, because return type was not a number or a list");
            }
            if(currFunct != res){
                currFunct->Destruct();
            }
            if(eval.isNewlyCreated()){
                res->Destruct();
            }
        }catch( std::runtime_error& e){
            std::cout << "ERORR | " << e.what() <<std::endl; 
            if(currFunct)currFunct->Destruct();
            currFunct = nullptr;
            return;
        }
    

   

}
//fact <- if(#0,mul(#0, fact(sub(#0, 1))),1)


int main(){
    ReadFromFile();
    // CLI();

    clean();

    // std::vector<Expression*> values(0);
    // values.push_back(new Number_Exp(3));
    // values.push_back(new Number_Exp(5));
    // Expression* exp = new List_Exp( values);
    // std::cout <<'[';
    // exp->print(std::cout);
    // std::cout <<']' << std::endl;

    // exp->Destruct();
  
    return 0;
}