#include <exception>
#include <iostream>
#include <stack>
#include <stdexcept>
#include <unordered_map>
#include <vector>
// #include "Checker.hpp"
#include "Objects.hpp"
#include "Reader.hpp"
#include "SyntaxTreeBuilder.hpp"
#include "tokenChecker.hpp"

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

void CLI(){
    std::string cmd;

      std::unordered_multimap<std::string, executeArgs> functions;

        functions.insert({"add",{2, [](std::vector<Node*> args) -> Node*
        {return new Add(args[0],args[1]);}}});
        functions.insert({"sub",{2, [](std::vector<Node*> args) -> Node*
        {return new Sub(args[0], args[1]);}}});

        functions.insert({"if",{3, [](std::vector<Node*> args) -> Node*
        {return new If(args[0], args[1],args[2]);}}});

        functions.insert({"real",{2, [](std::vector<Node*> args) -> Node*
        {return new VariableHolder(new RealNum(0));}}});




    STBuilder builder(functions);

    while(true){
        
        std::cout << "# ";
        getline(std::cin, cmd);

        if(cmd == ""){
            continue;
        }
        if(cmd == "end"){
            break;
        }
        // std::cout << cmd;
        Reader r;
        try{
            r.Read(cmd);
        }catch(std::invalid_argument e){
            std::cout << "| Error | " << e.what() << "\n";
        }

        // for(auto a : r.getTokens()){
        //     printToken(a);
        //     printTokenVal(a);
        // std::cout << "\n";
            
        // }

        std::vector<Token> tokens = r.getTokens();

        if(tokens.size() ==0){
            continue;
        }

        try{
            // std::cout << "Begin checking" << std::endl;
            tokenChecker checker;
            checker.check(tokens);
        }catch(std::runtime_error& e){
            std::cout << "\nERORR | " << e.what() <<std::endl;
            continue; 
        }

      
        



        Node *currFunct = nullptr;
        try{
            // std::cout << "Begin building" << std::endl;
            currFunct = builder.build(tokens);
        }catch( std::runtime_error& e){
            std::cout << "\nERORR | " << e.what() <<std::endl; 
            if(currFunct) currFunct->Destruct();
            currFunct = nullptr;
            continue;
        }

        try{
           
            // std::vector<Node*> args = {new RealNum(0)};
            if(tokens.size() >= 2 && tokens[1].token == LetBe){

            }else{
                if(!currFunct){
                    throw "Build failed";
                }
                std::cout << builder.arguments().size() << std::endl;              
                std::cout << std::endl<< (*currFunct)(builder.arguments()) << std::endl;
            }
            if(currFunct){
                currFunct->Destruct();
            }
            currFunct = nullptr;
        }catch(const char* e){
            std::cout << "ERORR | " << e <<std::endl; 
            if(currFunct)currFunct->Destruct();
            currFunct = nullptr;
            continue;
        }

    }
}


int main(){
    CLI();
  
    return 0;
}