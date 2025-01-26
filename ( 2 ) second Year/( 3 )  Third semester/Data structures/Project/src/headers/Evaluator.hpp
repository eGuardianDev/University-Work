
#ifndef _Evaluator_hpp__
#define _Evaluator_hpp__

#include "Expression.hpp"
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <unordered_map>


class Evaluator{

    typedef std::unordered_multimap<std::string, executeArgs> map;

    void fail(std::string data);
    
    double castToNum(Expression* exp);
    List_Exp* castToList(Expression* exp);

    bool areSubfunctionsDefined_OneArgument(Expression* exp);
    bool canFunctionSupportOneArguments(Function_Exp* func_exp);
    
    
    Expression* RunFunction(Function_Exp* curr);
    Expression* doAssociation(Associate_Exp* curr);

public:
    const bool isNewlyCreated()const;

    size_t countVariables();


    Evaluator(Expression* expression, map& functions, enviroment variables) : expression(expression), functionsList(functions), variables(variables) {}
    ~Evaluator(){}
    
    
    Evaluator(Evaluator&) = delete;
    Evaluator& operator=(Evaluator&) = delete;
    Evaluator(Evaluator&&) = delete;
    Evaluator& operator=(Evaluator&&) = delete;

    Expression* evaluate(int step = 0);

private:
    std::vector<std::string> integratedFunctions = {"add","sub","mul","div","pow","sqrt","sin","cos","eq","le","nand","if","list","head","tail","map","filter"};

    Expression* expression;
    map& functionsList;
    enviroment variables;

    bool newCreated = false;
};


#endif //_Evaluator_hpp__