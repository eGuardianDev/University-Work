#ifndef CLASS_COLLECTOR_HPP_
#define CLASS_COLLECTOR_HPP_

#include <any>
#include <string>
#include <vector>

#include "SharedMem.hpp"
#include "CoolParser.h"
#include "CoolParserBaseVisitor.h"

class ClassCollector : public CoolParserBaseVisitor {
public:
std::vector<std::string> errors;
private:



    std::string current_class;
    std::any visitProgram(CoolParser::ProgramContext *ctx) override {
        return visitChildren(ctx);
    }

    std::any visitClass(CoolParser::ClassContext *ctx) override {
        
        ClassInfo c;
        
        c.name = ctx->TYPEID(0)->getText();
        current_class = c.name;
        
        if(ctx->TYPEID(1) != nullptr)
            c.parent = ctx->TYPEID(1)->getText();
        
        
       

        if(!classTable.count(c.name)) {
            classTable[c.name] = c;
            if(c.parent == "Bool" || c.parent == "Int"  || c.parent=="String"){
                errors.push_back(
                    "`"+c.name+"` inherits from `"+c.parent+"` which is an error"
                );
            }
        }
        else{
            errors.push_back(
                "Type `"+c.name+"` already defined"
            );
        }

        classOrder.push_back(c.name);

        return  visitChildren(ctx);
    }
    std::any visitMethod(CoolParser::MethodContext *ctx) override {
        MethodInfo m;

        m.name = ctx->OBJECTID()->getText();
        m.returnType = ctx->TYPEID()->getText();
        m.body = ctx->expr();

        if(ctx->expr()->OBJECTID().size() == 1){
            if(ctx->expr()->OBJECTID(0)->getText() == "self"){
                m.isSelfReturn = true;
            }
        }


        for (auto *f : ctx->formal()) {
            m.formals.push_back({
                f->OBJECTID()->getText(),
                f->TYPEID()->getText()
            });
        }

        

        classTable[current_class].methods.push_back(m);

        return visitChildren(ctx);
    }
    std::any visitAttr(CoolParser::AttrContext *ctx) override {
        ClassInfo &cls = classTable[current_class];

        AttributeInfo attr;
        attr.name = ctx->OBJECTID()->getText();
        attr.type = ctx->TYPEID()->getText();
        attr.initExpr = ctx->expr();

        cls.attributes.push_back(attr);

        return visitChildren(ctx);
    }
    std::any visitFormal(CoolParser::FormalContext *ctx) override {
        return visitChildren(ctx);
    }
    std::any visitExpr(CoolParser::ExprContext *ctx) override {
        return visitChildren(ctx);
    }
    std::any visitVardecl(CoolParser::VardeclContext *ctx) override {
        return visitChildren(ctx);
    }

  public:
    ClassCollector() {}

   
    std::unordered_map<std::string, ClassInfo> classTable;
    std::vector<std::string> classOrder;

    std::unordered_map<std::string, ClassInfo> &check(CoolParser *parser){
       
        visitProgram(parser->program());
        parser->reset();

        return classTable;
    }
};


#endif //CLASS_COLLECTOR_HPP_