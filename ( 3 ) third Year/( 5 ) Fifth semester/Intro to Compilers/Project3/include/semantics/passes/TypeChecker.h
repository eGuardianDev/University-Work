#ifndef SEMANTICS_PASSES_TYPE_CHECKER_H_
#define SEMANTICS_PASSES_TYPE_CHECKER_H_

#include <any>
#include <string>
#include <vector>

#include "../../../src/semantics/SharedMem.hpp"
#include "CoolParser.h"
#include "CoolParserBaseVisitor.h"

class TypeChecker : public CoolParserBaseVisitor {
  private:
    // define any necessary fields
    std::vector<std::string> errors;

    std::unordered_map<std::string, std::string> inheritance_graph;
    std::unordered_map<std::string, ClassInfo> classes;
    
    AttributeInfo* getAttr(ClassInfo &cls, std::string attr_name);

    MethodInfo* lookupMethod(const std::string& className,const std::string& methodName);
    MethodInfo* getMethod(ClassInfo &cls, std::string method_name, std::string method_type = "");
    std::string LUB(std::string first, std::string second);
    bool isSubType(std::string sub, std::string parent);
    bool check_if_parent(std::string name, std::string curr_class, std::unordered_map<std::string, std::string>& graph){
      if(!graph.count(curr_class)) return false;
      
      do{
          curr_class = graph[curr_class];
          if(name == curr_class)
              return true;
        }
        while(graph.count(curr_class));

        return false;
    }
    std::unordered_set<std::string> predefined_types = {"Object", "IO", "Int", "String", "Bool"};
    std::unordered_set<std::string> predefined_classes = {"Object", "IO", "Int", "String", "Bool"};

    // override necessary visitor methods
    std::any visitProgram(CoolParser::ProgramContext *ctx) override;
    std::any visitClass(CoolParser::ClassContext *ctx) override;
    std::any visitMethod(CoolParser::MethodContext *ctx) override;
    std::any visitAttr(CoolParser::AttrContext *ctx) override;
    std::any visitFormal(CoolParser::FormalContext *ctx) override;
    std::any visitExpr(CoolParser::ExprContext *ctx) override;
    std::any visitVardecl(CoolParser::VardeclContext *ctx) override;
    // define helper methods

  public:
    // TODO: add necessary dependencies to constructor
    TypeChecker() {}

    // Typechecks the AST that the parser produces and returns a list of errors,
    // if any.
    std::vector<std::string> check(CoolParser *parser,std::unordered_map<std::string, std::string> &graph, std::unordered_map<std::string, ClassInfo> & classes );
};

#endif
