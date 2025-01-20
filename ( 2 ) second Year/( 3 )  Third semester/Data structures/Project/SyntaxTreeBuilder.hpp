
#include "Objects.hpp"
#include <iostream>
#include <ostream>
#include <stack>
#include <stdexcept>
#include <unordered_map>
#include <vector>
#include "Tokens.hpp"
class STBuilder{
    private:

    std::vector<Token> objs;
    std::vector<Node*> newFunctions;

    std::unordered_multimap<std::string, executeArgs>&  functions;

    int index = 0;

    Token &Peak(){
        if(index == objs.size()){
            problem("Uncomplete syntax");
        }
        return objs[index];
    }
    Token &Pop(){
        return objs[index++];
    }
    bool end(){
        return index >= objs.size();
    }
    void next(){
        ++index;
    }
    void reset(){
        index = 0;
    }
    void problem(const std::string& data){
        std::string res;
        res += data +"\n\n";
        reset();
        throw std::runtime_error(res);
    }

    public:

    STBuilder(std::unordered_multimap<std::string, executeArgs>& functions) : functions(functions){}
    ~STBuilder(){
        for(int i=0;i<newFunctions.size();++i){
            newFunctions[i]->Destruct();
        }
    }

    Node* build(std::vector<Token> _objs, int& _index){
        objs = _objs;
        index = _index;
        if(objs.size() == 0){
            throw "Empty vector no objects";
            return nullptr;
        }
        Node* root = nullptr;

        if(index == _objs.size()){
            return nullptr;
        }

        while(!end()){
            switch(Peak().token){
                case Variable:
                {
                    std::string nameOfFunc = Peak().val;
                    next();
                    if(Peak().token == LetBe){
                        next();
                         Node* res;
                        try{
                         res = build(objs,index);
                        }
                        catch(std::runtime_error& e){
                            if(root)root->Destruct();
                            throw e;
                        }
                        newFunctions.push_back(res);
                        functions.insert({nameOfFunc,{0, [res](std::vector<Node*> args) -> Node*
                        {return res->clone();}}});
                        return nullptr;

                    }else{
                        auto [left, right] = functions.equal_range(nameOfFunc);
                        if(left == nullptr){
                            problem("function with name \"" + nameOfFunc+ "\" is not defined");
                        }

                        if(Peak().token == Open_bracket){
                            next();
                            std::vector<Node*> args;

                            while(!end() && Peak().token != Close_bracket){
                                if(Peak().token == Comma){
                                    next();
                                    continue;
                                }else{
                                    try{
                                    args.push_back(build(objs, index));
                                    }catch(std::runtime_error& e ){
                                        if(root){
                                            root->Destruct();
                                        }
                                        throw e;
                                    }
                                }
                            }   
                            next();
                            // std::cout << "args count: "<< args.size() << std::endl;


                            bool found = false;
                            while(left != right){
                                if(args.size() == left->second.argc){
                                    return left->second.function(args);
                                    found =true;
                                    break;
                                }
                                ++left;
                            }
                            if(found){
                            }else{
                                for(int i =0;i<args.size();++i){
                                    args[i]->Destruct();
                                }

                                problem("Function " + nameOfFunc + " doesn't support this amounth of arguments");
                            }
                            
                            if(end()){
                                return root;
                            }
                        }
                    }
                }
                break;
                case Open_bracket:
                    throw std::logic_error("Token is Open_bracket");
                break;
                case Close_bracket:
                    throw std::logic_error("Token is Close_bracket");
                break;
                case Comma:
                    throw std::logic_error("Token is Comma");
                break;
                case Number:
                    root = new RealNum(std::stod(Peak().val));
                    next();
                    return root;
                break;

                default:
                    throw std::logic_error("undefined token type");
                break;

            }
            next();

        }

        return root;
    }

    Node* build(std::vector<Token> _objs){
        int index =0;
        return build(_objs,index);
    }

};