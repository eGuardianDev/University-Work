
#ifndef _Main_Logic_hpp_
#define _Main_Logic_hpp_
#include <iostream>
#include <stdexcept>
#include <unordered_map>
#include <vector>
#include <fstream>


#include "Evaluator.hpp"
#include "Expression.hpp"
#include "Lexer.hpp"
#include "Parser.hpp"
#include "tokenChecker.hpp"

class MainLogic{

public:

    MainLogic(){}
    ~MainLogic(){
        clean();
    }

    MainLogic(MainLogic&) = delete;
    MainLogic& operator=(MainLogic&) = delete;
    MainLogic(MainLogic&&) = delete;
    MainLogic& operator=(MainLogic&&) = delete;

    void ReadFromFile(std::string path);
    void CLI();

    public:
    
    void clean();
    void runCmd(std::string cmd);

private:

    std::unordered_multimap<std::string, executeArgs> functions;


};
#endif //_Main_Logic_hpp_