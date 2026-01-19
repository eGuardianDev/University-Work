#include "CoolSemantics.h"

#include "SharedMem.hpp"
#include <expected>
#include <string>
#include <vector>

#include "passes/TypeChecker.h"

#include "ClassCollector.hpp"

using namespace std;

string print_inheritance_loops_error(vector<vector<string>> inheritance_loops);

// used to check if method can return class
// checks if return class is parent
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

bool class_contains_method(ClassInfo class_info, std::string method_given){
    
    for(const auto &method : class_info.methods){
        if(method.name == method_given)
            return true;
    }
    return false;
}

bool class_contains_attribute(ClassInfo class_info, std::string attribute_given){
    
    for(const auto &attribute : class_info.attributes){
        if(attribute.name == attribute_given)
            return true;
    }
    return false;
}

std::vector<std::string> checkForLoop(std::string start, 
    std::unordered_map<std::string, std::string>& graph){
    // gets a node and checks for every parent of graph;
    // if loop exists, returns a string of loop
    // if none, returns empty 

    unordered_set<string> seen;
    vector<string> chain;

    string curr = start;

    while(curr != "" && graph.count(curr)){
        if(seen.count(curr)){
            vector<string> cycle;
            string begin = curr;

            cycle.push_back(begin);
            curr = graph[curr];
            while(curr != begin){
                cycle.push_back(curr);
                curr = graph[curr];
            } 
            return cycle;

        }else{
            seen.insert(curr);
            chain.push_back(curr);
            curr = graph[curr];
        }
    }
    return {};
}


void remove_same(vector<vector<string>> &input) {
    unordered_set<string> visited;

    for (int i = 0; i < input.size(); ) {
        bool removeList= false;
        for (const string &s : input[i]) {
            if (visited.count(s)) {
                removeList = true;
                break;
            }
        }
        if (removeList) {
            input.erase(input.begin() + i);
        } else {
            // add elements to visited
            for (const string &s : input[i])
                visited.insert(s);
            ++i;
        }
    }
}

void remove_empty(vector<vector<string>> &input){
    for (int i = 0; i < input.size();) {
        if(input[i].size() == 0){        
            input.erase(input.begin() + i);
        }else{
            ++i;
        }
    }
}

bool undefined_parent(std::string node, std::unordered_map<std::string,std::string>& graph){
    if(graph.count(node)){
        node = graph[node];
        if(node == "") return false;
        if(!graph.count(node)){
            return true;
        }
    }
    return false;
}

expected<void *, vector<string>> CoolSemantics::run() {
    vector<string> errors;

    
    std::unordered_set<std::string> predefined_types = {"Object", "IO", "Int", "String", "Bool"};
    std::unordered_set<std::string> predefined_classes = {"Object", "IO", "Int", "String", "Bool"};
    
    // * collect classes
    ClassCollector ClassCollector;
    std::unordered_map<std::string, ClassInfo> classes =ClassCollector.check(parser_);

    // std::cout << "Classes: " << classes.size() << std::endl;

    
    // * Build inheritance graph
    std::unordered_map<std::string, std::string> inheritance_graph; // class, parent
    std::vector<std::string> order_of_classes_appearance = ClassCollector.classOrder;
    
    for (const auto &[className, info] : classes) {
        if(inheritance_graph.count(className)){
            std::cerr << "ERROR | Two classes, same name\n";
        }else{
            inheritance_graph[className] = info.parent;
        }
        inheritance_graph[className] = info.parent;
    }
    inheritance_graph["Int"] = "Object";
    inheritance_graph["String"] = "Object";
    inheritance_graph["Bool"] = "Object";
    inheritance_graph["IO"] = "Object";
    inheritance_graph["Object"] = ""; // root
    // std::cout << "inheritance graph: " << inheritance_graph.size() << std::endl;

    // * Check for inheritance problems
    //  --> Check inheritance graph is a tree

    std::vector<std::vector<std::string>> errors_in_inheritance;

    // check for loops
    for(std::string curr : order_of_classes_appearance){
        std::vector<std::string> cycle = checkForLoop(curr, inheritance_graph);
        errors_in_inheritance.push_back(cycle);
    }
    // remove bad finds
    remove_same(errors_in_inheritance);
    remove_empty(errors_in_inheritance);

    // find undefined parents
    for(std::string curr : order_of_classes_appearance){
        if(predefined_classes.find(inheritance_graph[curr]) == predefined_classes.end()
            && undefined_parent(curr, inheritance_graph))
        {    
            std::string error = curr + " inherits from undefined class " + inheritance_graph[curr];
            errors.push_back(error);
        }
    }
    // add errors
    if(errors_in_inheritance.size() >0){
        errors.push_back(print_inheritance_loops_error(errors_in_inheritance));
    }



    // * Collect features
    // already done.


    // methods multi definitions
    for(auto &name : order_of_classes_appearance){
        auto &info = classes[name];
        std::unordered_set<std::string> visited;

        // std::cout << "Class: " << name <<std::endl;
        for( auto &methodInfo : info.methods){
            // std::cout << "\tMethod: " << methodName <<std::endl;
            if(visited.find(methodInfo.name) == visited.end()){
                visited.insert(methodInfo.name);
            }else{
                methodInfo.ignore = true; // stops further checks
                std::string error = "Method `"+methodInfo.name+"` already defined for class `"+name+"`";
                errors.push_back(error);
                // std::cout << methodInfo.name << " " << methodInfo.returnType << " c-" <<name <<" is ignored: " << methodInfo.ignore <<std::endl; 
            }
        }
        // visited.clear();
    }
    

    // check if correctly overwriten
    for( auto &name : order_of_classes_appearance){

         auto &class_info = classes[name];

        // if no parent, we are ok
        if(!inheritance_graph.count(class_info.name)){
            continue;
        }
        // check every method
        for( auto &methodInfo : class_info.methods){
            if(methodInfo.ignore) continue; // if it is ignored, skip it

            // check if parent has the method
            //to return
            auto oldest_parent_class_info = classes[class_info.parent];
            //to check
            auto current_parent_class_info = classes[class_info.parent];
            //check if has methods
            while(class_contains_method(current_parent_class_info, methodInfo.name))
            {
                //parent has the method
                oldest_parent_class_info = current_parent_class_info;
                //if parent has more parents continue
                if(current_parent_class_info.parent != ""){
                    current_parent_class_info = classes[current_parent_class_info.parent];
                }else {
                    break;
                }
            }
            // no more checking, oldest_parent_class_info is the oldest;

            //check methods if matching
            for( auto &parentMethod: oldest_parent_class_info.methods){
                if(parentMethod.ignore) continue;
                if(methodInfo.name == parentMethod.name){
                    //found matching functions
                    //return type
                    if(methodInfo.returnType != parentMethod.returnType){
                        std::string error = "Override for method "+methodInfo.name+" in class "+name+" has different signature than method in ancestor "+oldest_parent_class_info.name+" (earliest ancestor that mismatches)";
                        errors.push_back(error);
                    }else{
                        //check args
                        // for(int)
                        if(methodInfo.formals.size() != parentMethod.formals.size()){
                            //error
                            std::string error = "Override for method "+methodInfo.name+" in class "+name+" has different signature than method in ancestor "+oldest_parent_class_info.name+" (earliest ancestor that mismatches)";
                            errors.push_back(error);
                        }

                        for(int i =0 ;i<methodInfo.formals.size();++i){
                            if(methodInfo.formals[i].second != parentMethod.formals[i].second){
                                std::string error = "Override for method "+methodInfo.name+" in class "+name+" has different signature than method in ancestor "+oldest_parent_class_info.name+" (earliest ancestor that mismatches)";
                                errors.push_back(error);
                                break;
                            }
                        }
                    }
                    methodInfo.ignore = true;
                }else{
                    continue;
                }
            }
      
        }
    }

    // check return type
 

    for(const auto &name : order_of_classes_appearance){
        auto &info = classes[name];
        for( auto &methodInfo : info.methods){
            if(methodInfo.ignore) continue;   
            if(!classes.count(methodInfo.returnType) && !predefined_types.count(methodInfo.returnType) && methodInfo.returnType != "SELF_TYPE"){
                errors.push_back(
                    "Method `"+methodInfo.name+"` in class `"+name+"` declared to have return type `"+methodInfo.returnType+"` which is undefined"
                );
                methodInfo.ignore = true;
            }
        }
    }
    // argument type
    for(const auto &name : order_of_classes_appearance){
        const auto &class_info = classes[name];
        for( auto &methodInfo : class_info.methods){
            for(int i =0; i<methodInfo.formals.size();++i){
                std::string type = methodInfo.formals[i].second;
                if( type != "SELF_TYPE" && !predefined_classes.count(type) && !count(order_of_classes_appearance.begin(),order_of_classes_appearance.end(), type)){
                    std::string error ="Method `"+methodInfo.name+"` in class `"+class_info.name+"` declared to have an argument of type `"+type+"` which is undefined";
                    errors.push_back(error);
                    break;
                }
            }
        }
    }
    
    // return type if allowed
    for(const auto &name : order_of_classes_appearance){

        const auto &class_info = classes[name];

        // if no parent, we are ok
        if(!inheritance_graph.count(class_info.name)){
            continue;
        }
        // check every method
        for(const auto &attributesInfo : class_info.attributes){

            // check if parent has the method
            //to return
            auto oldest_parent_class_info = classes[class_info.parent];
            //to check
            auto current_parent_class_info = classes[class_info.parent];
        
            while(inheritance_graph.count(current_parent_class_info.name))
            {
                
                //parent has the method
                oldest_parent_class_info = current_parent_class_info;
                if(class_contains_attribute(current_parent_class_info, attributesInfo.name)){
                    break;
                }
                //if parent has more parents continue
                if(current_parent_class_info.parent != ""){
                    current_parent_class_info = classes[current_parent_class_info.parent];
                }else {
                    break;
                }
            }
            // std::cout << "Class: " << name << " attribute: " << attributesInfo.name << " oldest parent to have it " << oldest_parent_class_info.name  << std::endl; 
            for(const auto &parentAttributesInfo: oldest_parent_class_info.attributes){
                if(parentAttributesInfo.name == attributesInfo.name){
                    std::string error = "Attribute `"+attributesInfo.name+"` in class `"+class_info.name+"` redefines attribute with the same name in ancestor `"+oldest_parent_class_info.name+"` (earliest ancestor that defines this attribute)";
                    errors.push_back(error);
                }
            }
      
        }
    }


    std::vector<std::string> later_errors;
    // non existing type of attribute type
    for(const auto &name : order_of_classes_appearance){

        auto &class_info = classes[name];
        // check every method
        for(auto &attributesInfo : class_info.attributes){
            std::string name = attributesInfo.name;
            std::string type = attributesInfo.type;

            if(attributesInfo.type != class_info.name 
                && !predefined_types.count(type) && type != "SELF_TYPE"
                && !count(order_of_classes_appearance.begin(), order_of_classes_appearance.end(),type)){
                std::string error = "Attribute `"+name+"` in class `"+class_info.name+"` declared to have type `"+type+"` which is undefined";
                later_errors.push_back(error);
                attributesInfo.ignore = true;
            }
        }
    }

    // attribute multiple definitions
    for(const auto &name : order_of_classes_appearance){
        auto &info = classes[name];
        std::unordered_set<std::string> visited; 
        for( auto &attributeInfo : info.attributes){
            if(attributeInfo.ignore) continue;
            if(visited.find(attributeInfo.name) == visited.end()){
                visited.insert(attributeInfo.name);
            }else{
                std::string error = "Attribute `"+attributeInfo.name+"` already defined for class `"+name+"`";
                errors.push_back(error);

            }
        }
    }


    for( auto error : ClassCollector.errors){
        errors.push_back(error);
    }
    if(errors_in_inheritance.size() == 0){   
        for(const auto & error : TypeChecker().check(parser_,inheritance_graph,classes)){
            errors.push_back(error);
        }
    }

    for(const auto & data :later_errors){
        errors.push_back(data);
    }


    if (!errors.empty()) {
        return unexpected(errors);
    }

    // return the typed AST
    return nullptr;
}

string print_inheritance_loops_error(vector<vector<string>> inheritance_loops) {
    stringstream eout;
    eout << "Detected " << inheritance_loops.size()
         << " loops in the type hierarchy:" << endl;
    for (int i = 0; i < inheritance_loops.size(); ++i) {
        eout << i + 1 << ") ";
        auto &loop = inheritance_loops[i];
        for (string name : loop) {
            eout << name << " <- ";
        }
        eout << endl;
    }

    return eout.str();
}