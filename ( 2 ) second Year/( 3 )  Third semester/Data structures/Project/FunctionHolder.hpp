
#ifndef _FunctionHolder_Hpp__
#define _FunctionHolder_Hpp__

#include <functional>
#include <iostream>
#include <ostream>
#include <unordered_map>
#include <vector>
#include "Objects.hpp"
class FunctionHolder{

    typedef std::vector<Node*> argsList;
    typedef double returnType; 

    typedef std::function<returnType(argsList&)> functionType;

    struct command{
        int argc;
        functionType func;
    };

    private:

    std::unordered_multimap<std::string,command> list;
    

    void setup(){

        list.insert({"ping",{0,[](argsList&){std::cout <<"pong"<<std::endl; return 0;}}});
        list.insert({"ping",{1,[](argsList& args){std::cout <<"pong, " << args[1]<<std::endl; return 0;}}});
    }


    FunctionHolder(){
        setup();
    }
    public:

    double run(Node* command){
                
    }
    

};

#endif