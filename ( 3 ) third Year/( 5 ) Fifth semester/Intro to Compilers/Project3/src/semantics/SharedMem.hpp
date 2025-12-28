#ifndef SHARED_MEM_HPP__
#define SHARED_MEM_HPP__

#include <iostream>
#include <vector>
#include "../../include/CoolParser.h"

struct AttributeInfo {
    std::string name;
    std::string type;
    CoolParser::ExprContext* initExpr; 
    bool ignore = false;
};
struct MethodInfo {
    std::string name;
    std::string returnType;
    
    std::vector<std::pair<std::string, std::string>> formals;
    CoolParser::ExprContext* body;
    
    bool ignore = false;

    bool isSelfReturn = false;
    
    bool isOverride = false;    
};
struct ClassInfo {
    std::string name;
    std::string parent;
    
    std::vector<AttributeInfo> attributes;
    std::vector<MethodInfo> methods;
    
    CoolParser::ClassContext* ctx; 
};
#endif//SHARED_MEM_HPP__