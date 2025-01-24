
#ifndef _Evaluator_hpp__
#define _Evaluator_hpp__

#include "Expression.hpp"
#include <iostream>
#include <algorithm>
#include <stdexcept>
class Evaluator{
    void fail(std::string data){
        throw  std::runtime_error(data);
    }

   std::vector<std::string> integratedFunctions = {"add","sub","mul","div","pow","sqrt","sin","cos","eq","le","nand","IF","list","head","tail","map","filter"};

    Expression* expression;
    typedef std::unordered_multimap<std::string, executeArgs> map;
    map& functionsList;

    enviroment variables;

    double castToNum(Expression* exp){
        Evaluator eval(exp,functionsList, variables);
      
        Expression* castExp = eval.evaluate();

        List_Exp * listExp = dynamic_cast<List_Exp*>(castExp);
        if(dynamic_cast<List_Exp*>(exp)){
            fail("Cannot use list for this function");
        }else if(List_Exp * listExp = dynamic_cast<List_Exp*>(castExp); listExp) {
            listExp->Destruct();
            fail("Cannot use list for this function");
        }
        

        
        Number_Exp* evaluation = dynamic_cast<Number_Exp*>(castExp);
        
        if(!evaluation){
            fail("CastToNum failed");
        }
        double res = evaluation->value;

        if(eval.newCreated) evaluation->Destruct();
        return res;
    }
    
    List_Exp* castToList(Expression* exp){
        Evaluator eval(exp,functionsList, variables);
        List_Exp* evaluation = dynamic_cast<List_Exp*>(eval.evaluate());
        if(!evaluation){
            fail("castToList failed");
        }

        // if(eval.newCreated) evaluation->Destruct();
        return evaluation;
    }

   

    bool newCreated = false;
public:

   
    const bool isNewlyCreated() const{
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




            // ==================================
            // *      Standart operations
            
            if(curr->func_name == "add"){
                if(curr->arguments.size() == 2){
                    double res = castToNum(curr->arguments[0]) + castToNum(curr->arguments[1]);
                    newCreated = true;
                    return new Number_Exp(res);
                }else{
                    fail("invalid argument count");
                }
            }else if(curr->func_name == "sub"){
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
            }







            // ==================================
            // *      Logic functions
            

            else if(curr->func_name == "if"){
                if(curr->arguments.size() == 3){
                                        
                    double logicVal = castToNum(curr->arguments[0]);
                    if(logicVal != 0)
                        {
                            this->newCreated = true;
                            return new Number_Exp (castToNum(curr->arguments[1]));
                        }
                    else
                    {
                        this->newCreated = true;
                        return new Number_Exp (castToNum(curr->arguments[2]));
                    } 
                    

                }else{
                    fail("invalid argument count");
                }
            }





            // ==================================
            // *      List functions
            



            else if(curr->func_name == "map"){
                if(curr->arguments.size() == 2){


                // check function functionallity 

                    Function_Exp* transform_Func = dynamic_cast<Function_Exp*>(curr->arguments[0]);

                    if(!transform_Func){
                        fail("Must be manipulation function");
                    }
                    auto [begin, end] = functionsList.equal_range(transform_Func->func_name);
                    if(begin==nullptr){
                        fail("Passed function isn't fully defined");
                    }
                    bool argCountIs1 = false;
                    while(begin != end){
                        if(begin->second.argc == 1){
                            argCountIs1 = true;
                            break;
                        }else{
                            ++begin;
                        }
                    }
                    if(!argCountIs1){
                        fail("Function doesn't support solo argument");
                    } 


                // Check if passed argument is list

                    List_Exp* valList = dynamic_cast<List_Exp*>(curr->arguments[1]);
                    Evaluator eval(curr->arguments[1], functionsList, variables);
                
                    if(valList == nullptr){
                        Expression* currEval = eval.evaluate();
                        valList = dynamic_cast<List_Exp*>(currEval);
                        if(valList == nullptr){
                            if(eval.newCreated){currEval->Destruct();}
                            
                            fail("second arguments must be list or fuction that returns list");
                        }
                    
                    }

                // Start working on the list 
                    List_Exp* headVal = valList;

                    List_Exp* currNode = new List_Exp(0);
                    List_Exp* dummy = currNode;
                    
                    currNode->next = new List_Exp(0);
                    
                    while(valList){
                        currNode = currNode->next;

                        Number_Exp* temp = dynamic_cast<Number_Exp*>(valList->value);

                        if(!temp && valList->value){
                            fail("List doesn't contain number for some reason? - logic error");
                        }
                        if(!valList->value){
                            valList = valList->next;
                            continue;
                        }

                        transform_Func->arguments.push_back(temp);
                        double res;

                        res = castToNum(transform_Func); 
                        
                        transform_Func->arguments.pop_back();
                       
                        currNode->value = new Number_Exp(res);
                        currNode->next = new List_Exp(0);
                        valList = valList->next;
                    }
                    
                    delete currNode->next;
                    currNode->next = nullptr;
                    if(eval.newCreated){
                        headVal->Destruct();
                    }
                    
                    currNode = dummy->next;
                    delete dummy;
                    newCreated = true;


                    // currNode->print(std::cout);

                    return currNode;

                    }else{
                        fail("invalid argument count");
                    }



            }else if(curr->func_name == "head"){
                if(curr->arguments.size() == 1){

                     
                    List_Exp* valList = dynamic_cast<List_Exp*>(curr->arguments[0]);
                    if(valList == nullptr){
                        Evaluator eval(curr->arguments[0], functionsList, variables);
                        valList = dynamic_cast<List_Exp*>(eval.evaluate());
                    }

                    if(!valList && valList->value){
                        fail("List doesn't contain number for some reason? - logic error");
                    }
                    if(!valList->value){
                        valList->Destruct();
                        fail("Cannot use head on empty list");
                    }

                    double val = dynamic_cast<Number_Exp*>(valList->value)->value;
                    
                    valList->Destruct();
                    
                    newCreated = true;


                    return new Number_Exp(val);

                }else{
                    fail("invalid argument count");
                }
            }else if(curr->func_name == "filter"){
                if(curr->arguments.size() == 2){

                    Function_Exp* transform_Func = dynamic_cast<Function_Exp*>(curr->arguments[0]);
                   
                        
                    if(!transform_Func){
                        fail("Must be manipulation function");
                    }
                    auto [begin, end] = functionsList.equal_range(transform_Func->func_name);

                    if(begin==nullptr){
                        fail("Passed function isn't fully defined");
                    }


                    bool argCountIs1 = false;
                    while(begin != end){
                        if(begin->second.argc == 1){
                            argCountIs1 = true;
                            break;
                        }else{
                            ++begin;
                        }
                    }
                    if(!argCountIs1){
                        fail("Function doesn't support solo argument");
                    } 


                    Number_Exp* testVal = new Number_Exp(3);

                    Evaluator eval(transform_Func, functionsList,variables);
                    Expression* testRes = 0;
                    transform_Func->arguments.push_back(testVal);
                    try{
                        testRes = eval.evaluate();
                    }catch(std::runtime_error& e){
                        transform_Func->arguments.pop_back();
                        testVal->Destruct();
                        throw e;
                    }
                    transform_Func->arguments.pop_back();
                    testVal->Destruct();
                    if(eval.newCreated){
                        testRes->Destruct();
                    }


                    


                    List_Exp* valList = dynamic_cast<List_Exp*>(curr->arguments[1]);
                    if(valList == nullptr){
                        Evaluator eval(curr->arguments[1], functionsList, variables);
                        valList = dynamic_cast<List_Exp*>(eval.evaluate());
                    }

                    if(valList == nullptr){
                        fail("second arguments must be list or fuction that returns list");
                    }
                    
                    List_Exp* headVal = valList;

                    List_Exp* currNode = new List_Exp(0);
                    List_Exp* dummy = currNode;
                    
                    currNode->next = new List_Exp(0);
                    bool change = true;
                    while(valList){
                        if(change){
                            currNode = currNode->next;
                        }
                        change = true;

                        Number_Exp* temp = dynamic_cast<Number_Exp*>(valList->value);

                     
                        if(!temp && valList->value){
                            fail("List doesn't contain number for some reason? - logic error");
                        }
                        if(!valList->value){
                            valList = valList->next;
                            continue;
                        }



                        transform_Func->arguments.push_back(temp);

                        double res = castToNum(transform_Func); 

                        transform_Func->arguments.pop_back();
                       
                        if(res != 0 ){
                            currNode->value = new Number_Exp(temp->value);
                            currNode->next = new List_Exp(0);
                        }else{
                            change = false;
                        }
                        valList = valList->next;
                    }
                    
                    headVal->Destruct();
                    
                    currNode = dummy->next;
                    delete dummy;
                    newCreated = true;


                    // currNode->print(std::cout);

                    return currNode;

                }else{
                    fail("invalid argument count");
                }
            }else if(curr->func_name == "tail"){
                if(curr->arguments.size() == 1){

    

                    List_Exp* valList = dynamic_cast<List_Exp*>(curr->arguments[0]);
                    if(valList == nullptr){
                        Evaluator eval(curr->arguments[0], functionsList, variables);
                        valList = dynamic_cast<List_Exp*>(eval.evaluate());
                    }

                    if(valList == nullptr){
                        fail("second arguments must be list or fuction that returns list");
                    }
                    
                    if(!valList->value){
                        valList->Destruct();
                        fail("Cannot use tail on empty list");
                    }
                

                    List_Exp* toDelete = valList;
                    valList = valList->next;
                  
                    delete toDelete->value;
                    delete toDelete;
                    
                    newCreated = true;

                    return valList;

                }else{
                    fail("invalid argument count");
                }
            
            }else if(curr->func_name == "list"){
                
               
                // std::cout << "Size: "<<curr->arguments.size() << std:: endl;
                std::vector<Expression*> vals;
                for(int i =0;i<curr->arguments.size();++i){
                    vals.push_back( new Number_Exp(castToNum(curr->arguments[i])));
                }

                newCreated = true;
                return new List_Exp(vals);

           
            }
            
            

            // ==================================
            // *      User defined functions
            
            
            else{
                auto [begin, end] = functionsList.equal_range(curr->func_name);
                if(begin == nullptr){
                    fail("function with the name \"" +curr->func_name+ "\" doesn't exist");
                }
                while(begin != end){
                    // std::cout << "func argc: "<< begin->second.argc << std::endl;
                    // std::cout << "curr argc: "<< curr->arguments.size() << std::endl;
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
                       

                        newCreated = temp.newCreated;

                        // std::cout << toBeDestroyed.size() << std::endl;
                        for(int i =0;i<toBeDestroyed.size();++i){
                            toBeDestroyed[i]->Destruct();
                        }
                       

                        return res;
                    }else{
                        ++begin;
                    }
                }

                std::string error = "function doesn't support this amount of argument count";
                fail(error);

            }
            
            return curr;
        
        }else 
        if (Number_Exp* curr = dynamic_cast<Number_Exp*>(expression); curr != nullptr){
          
            return curr;
        
        }else 
        if (Argument_Exp* curr = dynamic_cast<Argument_Exp*>(expression); curr != nullptr){
            
            return variables[curr->index];
        
        }else 
        if (List_Exp* curr = dynamic_cast<List_Exp*>(expression); curr != nullptr){
            
            newCreated = false;
            return curr;
        
        }else 
        if (Associate_Exp* curr = dynamic_cast<Associate_Exp*>(expression); curr != nullptr){


            // define function 
            
            auto [begin, end] = functionsList.equal_range(curr->func_name);
            
            size_t argc = Evaluator(curr->expression,functionsList,variables).countVariables();
            if(begin != nullptr && begin != end){
                if(begin->second.argc == argc){
                    fail("Function with name and argument count exists");
                }else{
                    ++begin;
                }
            }
            if(argc == 0){
                auto eval =Evaluator(curr->expression,functionsList,variables);
                auto val=(eval.evaluate());
                functionsList.insert({curr->func_name, {argc, val}});
                if(eval.newCreated){
                    curr->expression->Destruct();
                }
            }else{
                functionsList.insert({curr->func_name, {argc, curr->expression}});
            }
            return curr;
        }else{
            return nullptr;
        }
    }

};


#endif //_Evaluator_hpp__