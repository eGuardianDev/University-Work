
#include "Objects.hpp"
#include <iostream>
#include <ostream>
#include <stack>
#include <stdexcept>
#include <vector>
#include "Tokens.hpp"
class STBuilder{
    private:

    std::vector<Token> objs;
    int index = 0;

    Token &Peak(){
        return objs[index];
    }
    Token &Pop(){
        return objs[index++];
    }
    bool end(){
        return index == objs.size();
    }
    void next(){
        ++index;
    }

    public:

    STBuilder(){}
    ~STBuilder(){}

    Object* build(std::vector<Token> _objs, int _index = 0){
        objs = _objs;
        index = _index;
        if(objs.size() == 0){
            throw "Empty vector no objects";
            return nullptr;
        }

        Object* root = nullptr;




        int countBrackets = 0;
        while(!end()){
            Token curr = Pop();
            
            switch(curr.token){
                case UNDEFINED:
                    throw std::logic_error("Something went very wrong - undefined token type");
                    break;
                // case Name:
                //     if(Peak().token != LetBe || Peak().token != Open_bracket){
                //         throw "Function without call or definition";
                //     }
                //     break;
                case Variable:
                    break;
                case Comma:
                    if(countBrackets == 0)
                        throw "Arguments outside brackets";
                    break;
                case LetBe:
                    if(countBrackets)
                        throw "Invalid attempt for definitions inside arguments";
                    
                    break;
                case Number:
                    break;
                case Open_bracket:
                    ++countBrackets;
                    break;
                case Close_bracket:
                    if(countBrackets==0)
                        throw "Invalid brackets";
                    --countBrackets;
                    break;
            }
        }
        if(countBrackets >0){
            throw "Invalid brackets";
        }


        return root;
    }

};