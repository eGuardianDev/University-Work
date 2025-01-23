
#ifndef _Evaluator_hpp__
#define _Evaluator_hpp__

#include "Expression.hpp"
#include <functional>
#include <iostream>
#include <locale>
#include <stdexcept>
class Evaluator{
    void fail(std::string data){
        throw  std::runtime_error(data);
    }

    Expression* expression;
    typedef std::unordered_multimap<std::string, executeArgs> map;
    map& functionsList;

    enviroment variables;

    double castToNum(Expression* exp){
        Evaluator eval(exp,functionsList, variables);
        Number_Exp* evaluation = dynamic_cast<Number_Exp*>(eval.evaluate());
        if(!evaluation){
            fail("CastToNum failed - maybe a list?");
        }
        double res = evaluation->value;

        if(eval.newCreated) evaluation->Destruct();
        return res;
    }
    bool newCreated = false;
public:
    bool newAlloc() const{
        return newCreated;
    }
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
                 
                    double res = castToNum(curr->arguments[0]) + castToNum(curr->arguments[1]);
                    newCreated = true;
                    return new Number_Exp(res);

                }else{
                    fail("invalid argument count");
                }
            }
            else if(curr->func_name == "sub"){
                if(curr->arguments.size() == 2){
                  double res = castToNum(curr->arguments[0]) - castToNum(curr->arguments[1]);
                    newCreated = true;
                    return new Number_Exp(res);

                }else{
                    fail("invalid argument count");
                }
            }else if(curr->func_name == "mul"){
                if(curr->arguments.size() == 2){
                   double res = castToNum(curr->arguments[0]) * castToNum(curr->arguments[1]);
                    newCreated = true;
                    return new Number_Exp(res);

                }else{
                    fail("invalid argument count");
                }
            }else if(curr->func_name == "div"){
                if(curr->arguments.size() == 2){
                    double divisor = castToNum(curr->arguments[1]);
                    if(divisor == 0){
                        fail("Trying to divide by 0");
                    }
                   double res = castToNum(curr->arguments[0]) /divisor;
                    newCreated = true;
                    return new Number_Exp(res);

                }else{
                    fail("invalid argument count");
                }
            }else if(curr->func_name == "if"){
                if(curr->arguments.size() ==3){
                                        
                    double logicVal = castToNum(curr->arguments[0]);
                    if(logicVal != 0)
                        return new Number_Exp (castToNum(curr->arguments[1]));
                    else return new Number_Exp (castToNum(curr->arguments[2]));
                    

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
                        enviroment toBeDestroyed(0);
                        for(int i =0;i<curr->arguments.size();++i){
                            auto tempVal =curr->arguments[i];
                            
                            auto eval =Evaluator(tempVal,functionsList,variables);
                                auto val=(eval.evaluate());

                            newVars.push_back(val);

                            if(eval.newCreated){
                                toBeDestroyed.push_back(val);
                            }
                        }

                        Evaluator temp(begin->second.function, functionsList, newVars);
                        
                        
                        Expression* res = temp.evaluate();

                        newCreated = true;

                        // std::cout << toBeDestroyed.size() << std::endl;
                        for(int i =0;i<toBeDestroyed.size();++i){
                            toBeDestroyed[i]->Destruct();
                        }
                       

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