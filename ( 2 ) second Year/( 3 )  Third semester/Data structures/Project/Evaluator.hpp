
#ifndef _Evaluator_hpp__
#define _Evaluator_hpp__

#include "Expression.hpp"
#include <iostream>
#include <stdexcept>
class Evaluator{
    void fail(std::string data){
        throw  std::runtime_error(data);
    }

    Expression* expression;
    typedef std::unordered_multimap<std::string, executeArgs> map;
    map& functionsList;

    enviroment variables;

    Number_Exp* castToNum(Expression* exp){
        return  dynamic_cast<Number_Exp*>(Evaluator(exp,functionsList, variables).evaluate());
    }
public:
    size_t countVariables(){
        if (Function_Exp* curr = dynamic_cast<Function_Exp*>(expression); curr != nullptr){
            size_t local = 0;
            for(int i =0;i<curr->arguments.size();++i){
                Expression* temp = curr->arguments[i];
                size_t res = Evaluator(temp, functionsList,variables).countVariables();
                local = std::max(res, local);
            }
            return local;
        }else 
        if (Number_Exp* curr = dynamic_cast<Number_Exp*>(expression); curr != nullptr){
            return 0;
        }else 
        if (Argument_Exp* curr = dynamic_cast<Argument_Exp*>(expression); curr != nullptr){
            return curr->index+1;
        }else 
        if (Associate_Exp* curr = dynamic_cast<Associate_Exp*>(expression); curr != nullptr){
            // return Evaluator(curr->expression,functionsList).countVariables();
            fail("Trying to count in associate expression");
        }
        return 0;
    }

    Evaluator(Expression* expression, map& functions, enviroment variables) : expression(expression), functionsList(functions), variables(variables) {}
    ~Evaluator(){}

    Expression* evaluate(int step =0){
        if (Function_Exp* curr = dynamic_cast<Function_Exp*>(expression); curr != nullptr){
            // std::cout << "this is function " << curr->func_name << std::endl; 
            
            if(curr->func_name == "add"){
                if(curr->arguments.size() == 2){
                    Number_Exp* left = castToNum(curr->arguments
                    [0]);

                    Number_Exp* right = castToNum(curr->arguments[1]);

                    int res = left->value +right->value;
                   
                    return new Number_Exp(res);

                }else{
                    fail("invalid argument count");
                }
            }
            else if(curr->func_name == "sub"){
                if(curr->arguments.size() == 2){
                    Number_Exp* left = dynamic_cast<Number_Exp*>(Evaluator(curr->arguments[0],functionsList, variables).evaluate());
                  

                    Number_Exp* right = dynamic_cast<Number_Exp*>(Evaluator(curr->arguments[1],functionsList, variables).evaluate());

                    int res = left->value -right->value;
                    return new Number_Exp(res);

                }else{
                    fail("invalid argument count");
                }
            }else if(curr->func_name == "mul"){
                if(curr->arguments.size() == 2){
                    Number_Exp* left = dynamic_cast<Number_Exp*>(Evaluator(curr->arguments[0],functionsList, variables).evaluate());

                    Number_Exp* right = dynamic_cast<Number_Exp*>(Evaluator(curr->arguments[1],functionsList, variables).evaluate());

                    int res = left->value *right->value;
                    return new Number_Exp(res);

                }else{
                    fail("invalid argument count");
                }
            }else if(curr->func_name == "if"){
                if(curr->arguments.size() ==3){
                    
                                        
                    Number_Exp* logic = dynamic_cast<Number_Exp*>(Evaluator(curr->arguments[0],functionsList, variables).evaluate());

                    if(logic->value != 0){

                        Number_Exp* True = dynamic_cast<Number_Exp*>(Evaluator(curr->arguments[1],functionsList, variables).evaluate());
                        return True;

                    }else{
                        Number_Exp* False = dynamic_cast<Number_Exp*>(Evaluator(curr->arguments[2],functionsList, variables).evaluate());

                        return False;
                    }

                }else{
                    fail("invalid argument count");
                }
            }
            else{
                auto [begin, end] = functionsList.equal_range(curr->func_name);
                if(begin == nullptr){
                    fail("function with the name \"" +curr->func_name+ "\" doesn't exist");
                }
                while(begin != end){
                    if(begin->second.argc == curr->arguments.size()){
                        enviroment newVars(0);

                        for(int i =0;i<curr->arguments.size();++i){
                            newVars.push_back(Evaluator(curr->arguments[i],functionsList,variables).evaluate());
                        }

                        Evaluator temp(begin->second.function, functionsList, newVars);
                        Expression* res = temp.evaluate();

                       

                        return res;
                    }else{
                        ++begin;
                    }
                }

                fail("function doesn't support the argument count");

            }
            
            return curr;
        }else 
        if (Number_Exp* curr = dynamic_cast<Number_Exp*>(expression); curr != nullptr){
            // std::cout << "this is number" << std::endl; 
            return curr;
        }else 
        if (Argument_Exp* curr = dynamic_cast<Argument_Exp*>(expression); curr != nullptr){
            // std::cout << "this is argument" << std::endl; 
            return variables[curr->index];
            // return curr;
        }else 
        if (Associate_Exp* curr = dynamic_cast<Associate_Exp*>(expression); curr != nullptr){
            // std::cout << "this is assoc" << std::endl; 
        
            auto [begin, end] = functionsList.equal_range(curr->func_name);
            
            size_t argc = Evaluator(curr->expression,functionsList,variables).countVariables();
            if(begin != nullptr && begin != end){
                if(begin->second.argc == argc){
                    fail("Function with name and argument count exists");
                }else{
                    ++begin;
                }
            }
            //all good
            functionsList.insert({curr->func_name, {argc, curr->expression}});
            // std::cout << "created successfully " << curr->func_name << std::endl;
            return curr;
        }else{
            //ignore this
            return nullptr;
        }
    }

};


#endif //_Evaluator_hpp__