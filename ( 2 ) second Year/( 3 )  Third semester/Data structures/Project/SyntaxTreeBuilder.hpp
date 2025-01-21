
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
    std::vector<Node*> newArgs;

    int maxArgumnets = 0;

    std::unordered_multimap<std::string, executeArgs>&  functions;

    int index = 0;
    bool afterLet = false;

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
    std::vector<Node*>& arguments(){
        return this->newArgs;
    }
    STBuilder(std::unordered_multimap<std::string, executeArgs>& functions) : functions(functions){}
    ~STBuilder(){
        for(int i=0;i<newFunctions.size();++i){
            newFunctions[i]->Destruct();
        }
    }


    Node* build(std::vector<Token> _objs, int& _index){
        afterLet = false;
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

                    if(nameOfFunc[0] == '#'){
                        int index = std::stoi(nameOfFunc.data()+1);
                        maxArgumnets = std::max(maxArgumnets, index);
                        std::cout << "Created #var\n";
                        return new VariableHolder(new RealNum(index));
                    }
                    else if(Peak().token == LetBe){
                        next();
                        Node* res;
                        afterLet = true;
                        try{
                            res = build(objs,index);
                        }
                        catch(std::runtime_error& e){
                            if(root)root->Destruct();
                            throw e;
                        }

                        newFunctions.push_back(res);

                        functions.insert({nameOfFunc,{maxArgumnets+1, [res](std::vector<Node*> args) -> Node*
                        {return res->clone(args);}}});

                        return nullptr;

                    }else{
                        auto [left, right] = functions.equal_range(nameOfFunc);
                        if(left == nullptr){
                            problem("function with name \"" + nameOfFunc+ "\" is not defined");
                        }

                        if(Peak().token == Open_bracket){
                            next();
                            std::vector<Node*> args(0);

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
                            std::cout << "args count: "<< args.size() << std::endl;
                            this->newArgs = args;

                            bool found = false;
                            while(left != right){
                                if(args.size() == left->second.argc){
                                    return left->second.function(args);
                                    found = true;
                                    break;
                                }
                                ++left;
                            }
                            if(!found){
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
        maxArgumnets = 0;
        return build(_objs,index);
    }

};