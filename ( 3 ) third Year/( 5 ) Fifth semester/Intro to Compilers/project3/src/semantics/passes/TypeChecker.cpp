#include "TypeChecker.h"

#include <string>
#include <vector>

#include "CoolParser.h"

using namespace std;

ClassInfo* currentClass = nullptr;  // C in class

// M in method
AttributeInfo* TypeChecker::getAttr(ClassInfo &cls, std::string attr_name){
    ClassInfo* current = &cls;
    while (true) {
        // Search methods in the current class
        for (auto& attr : current->attributes) {
            if (attr.name == attr_name) {
                    return &attr;

            }
        }
        // If no parent, lookup fails
        if (current->parent.empty()) {
            break;
        }
        // Move to parent class
        auto it = classes.find(current->parent);
        if (it == classes.end()) {
            break; // parent not found (should not happen in a valid program)
        }

        current = &it->second;
    }

    return nullptr;
}
// M in method
MethodInfo* TypeChecker::getMethod(ClassInfo &cls, std::string method_name, std::string method_type){
    ClassInfo* current = &cls;
    while (true) {
        // Search methods in the current class
        for (auto& method : current->methods) {
            if (method.name == method_name) {
                if(method_type != "" && method_type == method.returnType){
                    return &method;
                }
                if(method_type == ""){
                    return &method;
                }
                // if(method.returnType == "SELF_TYPE"){
                //     method.returnType = cls.name;
                // }

            }
        }
        // If no parent, lookup fails
        if (current->parent.empty()) {
            break;
        }
        // Move to parent class
        auto it = classes.find(current->parent);
        if (it == classes.end()) {
            break; // parent not found (should not happen in a valid program)
        }

        current = &it->second;
    }

    return nullptr;
}

// O in object
class ObjectEnv{
    std::vector<std::unordered_map<std::string, std::string>> scopes;
public:
    void enterScope() {
        scopes.emplace_back();
    }
    void exitScope() {
        scopes.pop_back();
    }
    void add(const std::string& name, const std::string& type) {
        scopes.back()[name] = type;
    }
    std::string lookup(const std::string& name) {
        for (auto it = scopes.rbegin(); it != scopes.rend(); ++it) {
            auto found = it->find(name);
            if (found != it->end()) {
                return found->second;
            }
        }
        return "";
    }
} O_Env;


bool TypeChecker::isSubType(std::string sub, std::string parent){
    if(sub == parent) return true;
 
    // No_Type conforms to everything
    if (sub == "No_Type") return true;

    std::string cur = sub;
    while (cur != "Object") {
        auto it = inheritance_graph.find(cur);
        if (it == inheritance_graph.end())
            break;

        cur = it->second;
        if (cur == parent)
            return true;
    }

    return parent == "Object";

}
std::string TypeChecker::LUB(std::string first, std::string second){

    if(first == second) return first;
    if(first == "") return second;
    if(second == "") return first;

    // Collect parents of first
    std::unordered_set<std::string> grand_parents;
    std::string cur = first;
    while (!cur.empty()) {
        grand_parents.insert(cur);
        cur = inheritance_graph[cur];
    }

    // find matches
    cur = second;
    while (!cur.empty()) {
        if (grand_parents.count(cur))
            return cur;
        cur = inheritance_graph[cur];
    }

    return "Object";
}

std::any TypeChecker::visitProgram(CoolParser::ProgramContext *ctx)  {
    return visitChildren(ctx);
}

std::any TypeChecker::visitClass(CoolParser::ClassContext *ctx)  {

    std::string name = ctx->TYPEID(0)->getText();


    if(predefined_classes.count(name)){
        errors.push_back(
                "Type `"+name+"` already defined"
        );
    }

    currentClass = &classes[name];
    O_Env.enterScope();

    // for every parent - enter scope

    ClassInfo *curr = &classes[currentClass->parent];
    while(curr){
        for(auto attribute : curr->attributes){
            std::string attribute_type = attribute.type;
           
            O_Env.add(attribute.name, attribute_type);
        }
        if(curr->parent == "") break;
        if(classes.count(curr->parent)){
            curr = &classes[curr->parent];
        }else 
        {
            break;
        }
    }

    for(auto attribute : currentClass->attributes){
        std::string attribute_type = attribute.type;
        O_Env.add(attribute.name, attribute_type);
    }

    


    auto toReturn = visitChildren(ctx);
    O_Env.exitScope();

    return toReturn;
}
MethodInfo* TypeChecker::lookupMethod(const std::string& className,
                                      const std::string& methodName) {

    std::string cur = className;

    while (true) {
        auto it = classes.find(cur);
        if (it == classes.end())
            return nullptr;

        for (auto& m : it->second.methods) {
            if (m.name == methodName)
                return &m;
        }

        if (cur == "Object")
            break;

        cur = it->second.parent;
    }

    return nullptr;
}



std::any TypeChecker::visitMethod(CoolParser::MethodContext *ctx)  {

    std::string name = ctx->OBJECTID()->getText();
    std::string T0 = ctx->TYPEID()->getText();

    O_Env.enterScope();

    MethodInfo* m = getMethod(*currentClass, name, T0);

    for(const auto& [n,t]: m->formals){
        if(t == "SELF_TYPE"){
            errors.push_back(
                "Formal argument `"+
                n+"` declared of type `SELF_TYPE` which is not allowed"
            );
            O_Env.exitScope();
            return T0;
        }
        O_Env.add(n,t);
    }

    std::string T0Prime = std::any_cast<std::string>(visit(ctx->expr()));

    
    
    if(T0Prime=="self"){
        T0Prime = "SELF_TYPE";
    }
    
    std::string expectedType = T0;
    
    if(T0 == "SELF_TYPE"){
        expectedType = currentClass->name;
    }else{
        expectedType = T0;
    }

    bool valid = false;

    if(T0 == "SELF_TYPE"){
        valid = (T0Prime == "SELF_TYPE");
    }else{
        if(T0Prime == "SELF_TYPE"){
            valid = isSubType(currentClass->name,expectedType);
        }else{
            valid = isSubType(T0Prime,expectedType);
        }
        
    }

    
    if(!valid && !m->ignore){    
        errors.push_back(
            "In class `"+currentClass->name+"` method `"+
            name+"`: `"+T0Prime+"` is not `"+T0+"`: type of method body is not a subtype of return type"
        );
    }

    O_Env.exitScope();
    return T0;
}

std::any TypeChecker::visitAttr(CoolParser::AttrContext *ctx)  {
   

    // attribute init
    std::string name = ctx->OBJECTID()->getText();
    std::string type = ctx->TYPEID()->getText();

    if(type == "SELF_TYPE"){
        type = currentClass->name;
    }

    //| OBJECTID ASSIGN expr                                              // assignment
    if(ctx->ASSIGN())
    {
        std::string expr_type = std::any_cast<std::string>(visit(ctx->expr()));
    
        
        if(expr_type == ""){
            return type;
        }
        
        if(expr_type == "SELF_TYPE"){
            expr_type = currentClass->name;
        }

        bool status = isSubType(expr_type,type);
        if(!status && expr_type != "0"){
            errors.push_back(
                "In class `"+currentClass->name+"` attribute `"+name+"`: `"+
                expr_type+"` is not `"+type+"`: type of initialization expression is not a subtype of declared type"
            );
        }  
    }
    
    return type;
    

}

std::any TypeChecker::visitFormal(CoolParser::FormalContext *ctx)  {
    return visitChildren(ctx);
}

std::any TypeChecker::visitExpr(CoolParser::ExprContext *ctx)  {


    //sequence
    if(ctx->OCURLY()){
        for(int i =0 ; i<ctx->expr().size()-1;++i){
            visit(ctx->expr(i));
        }
        std::string type = std::any_cast<std::string>(visit(ctx->expr(ctx->expr().size()-1)));
        if(type == ""){
            return std::string("No_Type");
        }
        return type;
    }
    // id  <- e
    if(ctx->OBJECTID().size() == 1 && ctx->ASSIGN() && ctx->expr().size() == 1 ){
        std::string name = ctx->OBJECTID(0)->getText();
        std::string lhsType = O_Env.lookup(ctx->OBJECTID(0)->getText());
        std::string rhsType = std::any_cast<std::string>(visit(ctx->expr(0)));
        
        if(lhsType == "") {
            errors.push_back(
                "Assignee named `"+name+"` not in scope"
            );
            return rhsType;
        }
        if (!isSubType(rhsType, lhsType)) {
            errors.push_back(
                "In class `" + currentClass->name + "` assignee `" + name +
                "`: `" + rhsType + "` is not `" + lhsType +
                "`: type of initialization expression is not a subtype of object type"
            );
            return lhsType;
        }

        if(lhsType != rhsType){
            return rhsType;
        }
        
        return lhsType;
    }
    
    // static dispatch
    if(ctx->expr().size() > 0 && ctx->AT() && ctx->DOT() && ctx->OPAREN() && ctx->CPAREN()){
//       expr ('@' TYPEID)? '.' OBJECTID '(' ( expr (',' expr )*)? ')'     // member invocation
       
        std::string e0 = ctx->expr(0)->getText();
        std::string T = ctx->TYPEID(0)->getText();
        std::string T0 = std::any_cast<std::string>(visit(ctx->expr(0)));

        std::string f = ctx->OBJECTID(0)->getText();

        bool isDefinedT = true;
        if(!classes.count(T)){
            errors.push_back(
               "Undefined type `"+T+"` in static method dispatch"
            );
            isDefinedT = false;
        }else if(!isSubType(T0,T)){
              errors.push_back(
                "`"+T0+"` is not a subtype of `"+T+"`"
            );
        }

        MethodInfo* M = getMethod(classes[T], f);
        MethodInfo* current_class_M = getMethod(classes[T0], f);
       

        if(isDefinedT && isSubType(T0,T)){    // casted as parent
            if(M == nullptr){   // parent doesn't have it
                errors.push_back(
                    "Method `"+f+"` not defined for type `"+T+"` in static dispatch"
                );
                return std::string("No_Type");
            }
        }
        if(isDefinedT && M == nullptr)
        {
            errors.push_back(
                "Method `"+f+"` not defined for type `"+T+"` in static dispatch"
            );
            return std::string("No_Type");
        }

        if(!isDefinedT && current_class_M == nullptr){
            errors.push_back(
                "Method `"+f+"` not defined for type `"+T0+"` in static dispatch"
            );
            return std::string("No_Type");
        }

        if(M == nullptr){
            return std::string("No_Type");
        }
        
        

        int argsCount = ctx->expr().size()-1;

        if(argsCount != M->formals.size()){
            errors.push_back(
                "Method `"+f+"` of type `"+T+"` called with the wrong number of arguments; "+std::to_string(M->formals.size())
                +" arguments expected, but "+std::to_string(argsCount)+" provided"
            );
        }else{
            bool isGood = true;
            std::vector<std::string> p_errors;
            std::string error =  "Invalid call to method `"+e0+"` from class `"+T+"`:";
            p_errors.push_back(error);
            for(int i=1;i<argsCount+1;++i){
                std::string type = std::any_cast<std::string>(visit(ctx->expr(i)));
                if(type != M->formals[i-1].second && !isSubType(type, M->formals[i-1].second)){
                    isGood = false;
                    error=(
                        "  `"+type+"` is not a subtype of `"+M->formals[i-1].second+"`: argument at position "+std::to_string(i-1)+" (0-indexed) has the wrong type"
                        );
                    p_errors.push_back(error);
                }
            }
            if(!isGood){
                for(auto & a : p_errors)
                    errors.push_back(a);
            }
        }

        std::string toReturn;
        toReturn = M->returnType;
        if(toReturn == "SELF_TYPE"){
            toReturn = currentClass->name;
        }
        return toReturn;


    }

// expr   : expr '.' OBJECTID '(' ( expr (',' expr )*)? ')'     // member invocation
    // // dispatch
    if(ctx->expr().size() > 0 && ctx->DOT() && ctx->OPAREN() && ctx->CPAREN()){
      std::string caller = ctx->expr(0)->getText();
        std::string caller_type = std::any_cast<std::string>(visit(ctx->expr(0)));

        if(caller_type == "SELF_TYPE"){
            caller_type = currentClass->name;
        }
        
        std::string function = ctx->OBJECTID(0)->getText();
        
        std::string returnType = "" ;// O_Env.lookup(function);
        
        MethodInfo* method = getMethod(classes[caller_type], function);

        if(method){
            returnType = method->returnType;
        }

        if(O_Env.lookup(caller) == ""){
            return std::string("No_Type");
        }

        auto it = classes.find(caller_type);


        ClassInfo& cls = it->second;


        if(caller_type == "String"){
            if(function == "length") return std::string("Int");
            if(function == "concat") return std::string("String");
            if(function == "substr") return std::string("String");
        } 
            
        if(returnType == ""){//} || flag == false){
            errors.push_back(
                "Method `"+function+"` not defined for type `"+caller_type+"` in dynamic dispatch"
            );
            return std::string("No_Type");
        }

        
        int argsCount = ctx->expr().size()-1;

        if(argsCount != method->formals.size()){
            errors.push_back(
                "Method `"+function+"` of type `"+caller_type+"` called with the wrong number of arguments; "+std::to_string(method->formals.size())
                +" arguments expected, but "+std::to_string(argsCount)+" provided"
            );
        }else{
            bool isGood = true;
            std::vector<std::string> p_errors;
            std::string error =  "Invalid call to method `"+caller+"` from class `"+caller_type+"`:";
            p_errors.push_back(error);
            for(int i=1;i<argsCount+1;++i){
                std::string type = std::any_cast<std::string>(visit(ctx->expr(i)));
                if(type != method->formals[i-1].second && !isSubType(type, method->formals[i-1].second)){
                    isGood = false;
                    error=(
                        "  `"+type+"` is not a subtype of `"+method->formals[i-1].second+"`: argument at position "+std::to_string(i-1)+" (0-indexed) has the wrong type"
                        );
                    p_errors.push_back(error);
                }
            }
            if(!isGood){
                for(auto & a : p_errors)
                    errors.push_back(a);
            }
        }

        return returnType;
    }
    
    
// vardecl : OBJECTID ':' TYPEID ( ASSIGN expr )?;
//LET vardecl (',' vardecl)* IN expr                                // let-in; needs to be here for precedence
    if(ctx->LET()){
        int expr_count = ctx->expr().size();
        int vardecl_count = ctx->vardecl().size();

        O_Env.enterScope();
        for(int i =0; i <vardecl_count;++i){
            std::string type = std::any_cast<std::string>(visit(ctx->vardecl(i)));
        }
        std::string return_type = std::any_cast<std::string>(visit(ctx->expr(0)));
        
        O_Env.exitScope();

        return return_type;
    }


    // arithmetics
    if((ctx->PLUS() || ctx-> MINUS() || ctx->STAR() || ctx->SLASH()) && ctx->expr().size() == 2){
        std::string type1 = std::any_cast<std::string>(visit(ctx->expr(0)));
        std::string type2 = std::any_cast<std::string>(visit(ctx->expr(1)));
        if(type1 != "Int"){
            errors.push_back(
                "Left-hand-side of arithmetic expression is not of type `Int`, but of type `"+type1+"`"
            );
        }
        if(type2 != "Int"){
            errors.push_back(
                "Right-hand-side of arithmetic expression is not of type `Int`, but of type `"+type2+"`"
            );            
        }

        return std::string("Int");
    }

    // while
    if(ctx->WHILE() && ctx->LOOP() && ctx->POOL() && ctx->expr().size() ==2){
        std::string type1 = std::any_cast<std::string>(visit(ctx->expr(0)));

        if(type1 != "Bool" && inheritance_graph[type1] != "Bool"){
            errors.push_back(
                "Type `"+type1+"` of while-loop-pool condition is not `Bool`"
            );
        }


        return std::string("Object");
    }

    // if
    if(ctx->IF() && ctx->THEN() && ctx->ELSE() && ctx->expr().size() == 3){
        std::string type1 = std::any_cast<std::string>(visit(ctx->expr(0)));
        std::string type2 = std::any_cast<std::string>(visit(ctx->expr(1)));
        std::string type3 = std::any_cast<std::string>(visit(ctx->expr(2)));

        if(type1 != "Bool"){
            errors.push_back(
                "Type `"+type1+"` of if-then-else-fi condition is not `Bool`"
            );
        }

        std::string returnType = LUB(type2, type3); // lub;
        return returnType;
    }

    // caseof
    if(ctx->CASE() && ctx->OF() && ctx->expr().size()>0){
      
//    | CASE expr OF (OBJECTID ':' TYPEID DARROW expr ';' )+ ESAC         // case-of-esac
        std::string checker = ctx->expr(0)->getText();
        
        int optionsCount = ctx->OBJECTID().size();

        std::unordered_map<std::string,std::string> visited;
        std::vector<std::string> types;
        
        for(int i = 0;i<optionsCount; ++i){
            O_Env.enterScope();
            std::string object = ctx->OBJECTID(i)->getText();
            std::string type = ctx->TYPEID(i)->getText();
            
            if(type == "SELF_TYPE"){
                errors.push_back(
                    "`"+object+"` in case-of-esac declared to be of type `SELF_TYPE` which is not allowed"
                );
            }

            else if(!classes.count(type)){
                errors.push_back(
                    "Option `"+object+"` in case-of-esac declared to have unknown type `"+  type+"`"
                );
            }else O_Env.add(object,type);
            
            if(visited.count(type)){
                errors.push_back(
                    "Multiple options match on type `"+type+"`"
                );
            }else visited[type] = object;
            
            std::string expr_type = std::any_cast<std::string>(visit(ctx->expr(i+1)));
            types.push_back(expr_type);
        
            
      
            if(expr_type == ""){
               
            }
            O_Env.exitScope();
        }

        std::string returnType = ""; // lub;
        if(optionsCount == 1) returnType = types[0];
        else{
            returnType = LUB(types[0],types[1]);
            for(int i = 2;i<optionsCount; ++i){
                returnType = LUB(returnType,types[i]);
            }
        }

        return returnType;
    }


    // new 
    if(ctx->NEW()){
        std::string type = ctx->TYPEID(0)->getText();
        if(type== "SELF_TYPE"){
            return type;
        }else{
            if(inheritance_graph.count(type)){
                return type;
            }else{
                errors.push_back(
                    "Attempting to instantiate unknown class `"+type+"`"
                );
                return std::string("No_Type");
            }
        }
    }


    // isvoid
    if(ctx->ISVOID() && ctx->expr().size() == 1){
        return std::string("Bool");
    }


    // neg
    if(ctx->TILDE() && ctx->expr().size() == 1){
        std::string type1 = std::any_cast<std::string>(visit(ctx->expr(0)));
        if(type1 != "Int"){
            errors.push_back(
                "Argument of integer negation is not of type `Int`, but of type `"+type1+"`"
            );
        }
        return std::string("Int");
    }

    // not
    if(ctx->NOT() && ctx->expr().size() == 1){
        std::string type1 = std::any_cast<std::string>(visit(ctx->expr(0)));
        if(type1 != "Bool"){
            errors.push_back(
                "Argument of boolean negation is not of type `Bool`, but of type `"+type1+"`"
            );
        }
        return std::string("Bool");
    }
 

    // equal
    if(ctx->EQ() && ctx->expr().size() == 2){
        std::string type1 = std::any_cast<std::string>(visit(ctx->expr(0)));
        std::string type2 = std::any_cast<std::string>(visit(ctx->expr(1)));
        if((type1 == "Int" || type1 == "String" || type1 == "Bool") && type1 == type2){}
        else{
            if(!ctx->expr(1)->NEW()){
                errors.push_back(
                    "A `"+type1+"` can only be compared to another `"+type1+"` and not to a `"+type2+"`"
                );
            }
        }
        return std::string("Bool");
    }
    // compare
    if( (ctx ->LE() || ctx->LT()) && ctx->expr().size() == 2){
        std::string type1 = std::any_cast<std::string>(visit(ctx->expr(0)));
        std::string type2 = std::any_cast<std::string>(visit(ctx->expr(1)));
         if(type1 != "Int"){
            errors.push_back(
                "Left-hand-side of integer comparison is not of type `Int`, but of type `"+type1+"`"
            );
        }
        if(type2 != "Int"){
            errors.push_back(
                "Right-hand-side of integer comparison is not of type `Int`, but of type `"+type2+"`"
            );            
        }
        return std::string("Bool");
    }

    // ( expr )
    if(ctx->OPAREN() && ctx->expr().size() == 1 && ctx->CPAREN() && ctx->OBJECTID().size() == 0){
        std::string type = std::any_cast<std::string>(visit(ctx->expr(0)));
        return type;
    }

    if(ctx->STR_CONST() != nullptr){
        return std::string("String");
    }
    if(ctx->INT_CONST() != nullptr){
        return std::string("Int");
    }
    if(ctx->BOOL_CONST() != nullptr){
        return std::string("Bool");
    }

    if(ctx->OPAREN()&& ctx->OBJECTID().size() == 1){
        MethodInfo* type = getMethod(*currentClass, ctx->OBJECTID(0)->getText());
        if(type){
            return type->returnType;
        }
        return std::string("No_Type");
    }

    if(ctx->OBJECTID().size() == 1 ){
        std::string name = ctx->OBJECTID(0)->getText();
        if(name == "self") return std::string("SELF_TYPE");
        std::string type = O_Env.lookup(name);
        if(type == ""){
            errors.push_back(
                "Variable named `"+name+"` not in scope"
            );
        }
        return type;
    }

    return std::string("Object");
}

std::any TypeChecker::visitVardecl(CoolParser::VardeclContext *ctx)  {
// vardecl : OBJECTID ':' TYPEID ( ASSIGN expr )?;
    
    std::string name = ctx->OBJECTID()->getText();
    std::string type_prime = ctx->TYPEID()->getText();
    
    
    if(ctx->ASSIGN()){
        std::string value = std::any_cast<std::string>(visit(ctx->expr()));
        if(!isSubType(value, type_prime)){
            if(value !=""){   
                errors.push_back(
                    "Initializer for variable `"+name
                    +"` in let-in expression is of type `"+value+
                    "` which is not a subtype of the declared type `"
                    +type_prime+"`"
                );
            }
        }

    }
    O_Env.add(name, type_prime);
    
    return std::string("vardecl");
}

vector<string> TypeChecker::check(CoolParser *parser,std::unordered_map<std::string, std::string> &graph, std::unordered_map<std::string, ClassInfo> & classes ) {
    inheritance_graph = graph;
    this->classes = classes;
    visitProgram(parser->program());
    parser->reset();

    return std::move(errors);
}