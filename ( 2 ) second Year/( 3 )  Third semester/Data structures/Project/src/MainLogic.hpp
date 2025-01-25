
#ifndef _Main_Logic_hpp_
#define _Main_Logic_hpp_
#include <iostream>
#include <stdexcept>
#include <unordered_map>
#include <vector>
#include <fstream>


#include "./headers/Evaluator.hpp"
#include "./headers/Expression.hpp"
#include "./headers/Lexer.hpp"
#include "./headers/Parser.hpp"
#include "./headers/tokenChecker.hpp"

class MainLogic{


    std::unordered_multimap<std::string, executeArgs> functions;

    // #define Debug_mode

    #ifdef Debug_mode
    void printToken(Token token){
        std::cout << TokenToString[token.token];
    }
    void printTokenVal(Token token){
        std::cout << token.val;
    }
    #endif

public:

    MainLogic(){}
    ~MainLogic(){
        clean();
    }

    MainLogic(MainLogic&) = delete;
    MainLogic& operator=(MainLogic&) = delete;
    MainLogic(MainLogic&&) = delete;
    MainLogic& operator=(MainLogic&&) = delete;

    void ReadFromFile(std::string path){
        std::fstream File(path);

        if(!File.is_open())
        {
            std::cout << "File \"" << path << "\" cannot be opened" << std::endl;   
        }
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

    
    public:

    void clean(){
        for(auto it = functions.begin(); it != functions.end();){
            it->second.function->Destruct();
            it++;
        }
    }

    void runCmd(std::string cmd){
    

        Lexer r;
        Parser builder;
        tokenChecker checker;

        try{
            r.Read(cmd);
        }catch(std::invalid_argument e){
            std::cout << "| Error | " << e.what() << "\n";
        }


        std::vector<Token> tokens = r.getTokens();

        if(tokens.size() ==0){
            return;
        }

        try{
            checker.check(tokens);
        }catch(std::runtime_error& e){
            std::cout << "\nERORR | " << e.what() <<std::endl;
            return; 
        }

        

        Expression *currFunct = nullptr;
        try{
            currFunct = builder.build(tokens);
        }catch( std::runtime_error& e){
            std::cout << "\nERORR | " << e.what() <<std::endl; 
            if(currFunct) currFunct->Destruct();
            currFunct = nullptr;
            return;
        }



        try{
            std::vector<Expression*> env(0);
            Evaluator eval(currFunct,functions, env);
            Expression* res = eval.evaluate();
                        
            if (Number_Exp* curr = dynamic_cast<Number_Exp*>(res); curr != nullptr){
            
                curr->print(std::cout);
                std::cout << std::endl;
            
            } else if (Associate_Exp* curr = dynamic_cast<Associate_Exp*>(res); curr != nullptr){

                delete res;
                return;

            } else if (List_Exp* curr = dynamic_cast<List_Exp*>(res); curr != nullptr){
            
                std::cout << "[";
                curr->print(std::cout);
                std::cout << "]" << std::endl;
            
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
};
#endif //_Main_Logic_hpp_