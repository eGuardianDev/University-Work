#ifndef _Checker_hpp__
#define _Checker_hpp__

#include "Objects.hpp"
#include "Tokens.hpp"
#include <iostream>
#include <queue>
#include <vector>
class Checker{

    Object* main;

    std::queue<Object**> nextOp;

    public:
    Checker(){}
    ~Checker(){}


    bool Check(std::vector<TokenType>& tokens){
        int index =0;
        nextOp.push(&main);
        Object** curr;
        while(!nextOp.empty()){
            curr = nextOp.front();
            nextOp.pop();
            std::cout << "create " << &*curr << '\n';
            switch(tokens[index]){
                case IF:{
                    IfDef *temp = new IfDef();
                    *curr = temp;
                    nextOp.push(&temp->logic);
                    nextOp.push(&temp->t);
                    nextOp.push(&temp->f);
                    break;
                }
                case Number:
                std::cout << "setting "<< &*curr <<'\n';
                *curr = new RealNumber(3);
                break;
                case ADD:{
                    AddFunc *temp = new AddFunc();
                    *curr = temp;
                    nextOp.push(&temp->a);
                    nextOp.push(&temp->b);
                    break;
                }
                
            }
            ++index;
        }
        return true;
    }

    double run(){
        return (*main)();
    }

};
#endif

