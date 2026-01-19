#ifndef CUSTOM_EXPRESSION_GENERATOR
#define CUSTOM_EXPRESSION_GENERATOR

#include <iostream>
#include <ostream>
#include "CodeEmitter.h"

#include "semantics/typed-ast/Expr.h"
#include "semantics/typed-ast/Assignment.h"
#include "semantics/typed-ast/StaticDispatch.h"
#include "semantics/typed-ast/StringConstant.h"
#include "semantics/typed-ast/IntConstant.h"
#include "semantics/typed-ast/ObjectReference.h"
#include "semantics/typed-ast/Arithmetic.h"
#include "semantics/typed-ast/ParenthesizedExpr.h"
#include "semantics/typed-ast/Sequence.h"
#include "semantics/typed-ast/IfThenElseFi.h"
#include "semantics/typed-ast/EqualityComparison.h"
#include "semantics/typed-ast/IntegerNegation.h"
#include "semantics/typed-ast/BoolConstant.h"
#include "semantics/typed-ast/BooleanNegation.h"
#include "semantics/typed-ast/IntegerComparison.h"
#include "semantics/typed-ast/ObjectReference.h"
#include "semantics/typed-ast/DynamicDispatch.h"
#include "semantics/typed-ast/MethodInvocation.h"
#include "semantics/typed-ast/IsVoid.h"
#include "semantics/typed-ast/LetIn.h"
#include "semantics/typed-ast/Vardecl.h"
#include "semantics/typed-ast/Assignment.h"
#include "semantics/typed-ast/NewObject.h"
#include "semantics/typed-ast/WhileLoopPool.h"

#include "StringTable.h"


#include "semantics/ClassTable.h"

class ExpressionGenerator{
   
    struct LocalLoc {
    int fp_offset;   // where the variable lives in the current stack frame
    };

    std::vector<std::unordered_map<std::string, LocalLoc>> scopes_;
    std::vector<int> next_fp_offset_;
    int next_local_fp_offset_ = 0;  // we’ll make it negative: -4, -8, -12...
    // int current_class_index_ = -1;  // set when emitting a method


    void push_scope() { next_fp_offset_.push_back(next_local_fp_offset_);
                         scopes_.push_back({}); }
    void pop_scope()  { 
        next_fp_offset_.pop_back();
        next_local_fp_offset_ = next_fp_offset_.back();  
        scopes_.pop_back();}

    std::optional<LocalLoc> lookup_local(const std::string& name) const {
        for (int i = (int)scopes_.size() - 1; i >= 0; --i) {
            auto it = scopes_[i].find(name);
            if (it != scopes_[i].end()) return it->second;
        }
        return std::nullopt;
    }

    void bind_local(const std::string& name, LocalLoc loc) {
        scopes_.back()[name] = loc;
    }




    ClassTable* class_table_;  

    int count_ifs_ = 0;
    int count_equality_ = 0;

    int count_comparison = 0;
    int count_loops = 0;

    void emit_int_constant(std::ostream &out, const IntConstant *expr);
    void emit_if_else(std::ostream &out, const IfThenElseFi *expr);
    void emit_static_dispatch(std::ostream &out, const StaticDispatch *expr);
    void emit_string_constant(std::ostream &out, const StringConstant *expr);
    void emit_arithmetic(std::ostream &out, const Arithmetic *expr);
    void emit_equality_comparison(std::ostream &out, const EqualityComparison *expr);
    void emit_integer_negation(std::ostream &out, const IntegerNegation *expr);
    void emit_bool_constant(std::ostream &out, const BoolConstant *expr);
    void emit_boolean_negation(std::ostream &out, const BooleanNegation *expr);
    void emit_integer_comparison(std::ostream &out, const IntegerComparison *expr);
    void emit_object_reference(std::ostream &out, const ObjectReference *expr);
    void emit_dynamic_dispatch(std::ostream &out, const DynamicDispatch *expr);
    void emit_method_invocation(std::ostream &out, const MethodInvocation *expr);
    void emit_is_void(std::ostream &out, const IsVoid *expr);
    void emit_let_in(std::ostream &out, const LetIn *expr);
    void emit_vardecl(std::ostream &out, const Vardecl *expr);
    void emit_assignment(std::ostream &out, const Assignment *expr);
    void emit_new_object(std::ostream &out, const NewObject *expr);
    void emit_while_loop_pool(std::ostream &out, const WhileLoopPool *expr);
    
    StringTable string_table;

public:
    std::string current_class;
    std::string current_function;
    ExpressionGenerator(ClassTable* class_table)
    : class_table_(class_table) {}

    
    StringTable& get_string_table() {return string_table;}

    void emit_expr(std::ostream &out, const Expr *expr);
    // void emit_assignment(std::ostream &out, const Assignment *expr);
};

#endif// CUSTOM_EXPRESSION_GENERATOR
