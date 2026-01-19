#include "codegen/ExpressionGenerator.h"
#include "semantics/typed-ast/IntConstant.h"

#include "CodeEmitter.h"

using namespace riscv_emit;

void ExpressionGenerator::emit_expr(std::ostream &out, const Expr *expr) {
  
    if (auto dynamic = dynamic_cast<const DynamicDispatch *>(expr)) {
        // out << "dynamic =========================================================================== \n";
        emit_dynamic_dispatch(out, dynamic);
        return; 
    }
    if (auto method = dynamic_cast<const MethodInvocation *>(expr)) {
        // out << "method =========================================================================== \n";
        // abort();
        emit_method_invocation(out, method);
        return; 
    }
    if (auto static_dispatch = dynamic_cast<const StaticDispatch *>(expr)) {
        // out << "Static ==================================================================================\n";
        emit_static_dispatch(out, static_dispatch);
        return; 
    }
    if (auto string_constant = dynamic_cast<const StringConstant *>(expr)) {
        emit_string_constant(out, string_constant);
        return; 
    }
    if (auto int_constant = dynamic_cast<const IntConstant *>(expr)) {
        emit_int_constant(out, int_constant);
        return; 
    }
    if (auto block = dynamic_cast<const Sequence *>(expr)) {
        for (auto e : block->get_sequence()) {
            // emit_move(out, ArgumentRegister{0}, SavedRegister{0});
            emit_expr(out, e);
            // emit_move(out, SavedRegister{0}, ArgumentRegister{0});
        }
        return;
    } 
    if (auto obj = dynamic_cast<const ObjectReference *>(expr)) {
        std::string name = obj->get_name();
        // out << "Object reference " << name << " : =============================\n";
        if(name =="self"){
            return;
        }
        
        if (auto loc = lookup_local(name)) {
            emit_load_word(out, ArgumentRegister{0},
                        MemoryLocation{loc->fp_offset, FramePointer{}});
            return;
        }

        int cls = class_table_->get_index(current_class);
        auto args = class_table_->get_argument_names(cls, current_function);  // ["x"]

        for (int i = 0; i < (int)args.size(); ++i) {
            int off = 4 * (i + 1);
            emit_load_word(out, ArgumentRegister{0},
                        MemoryLocation{off, FramePointer{}});
            return;
        }


        auto pos = name.find('_');
        std::string basedName = name.substr(0, pos);

        
        int index_of_class = class_table_->get_index(current_class);
        auto vec = class_table_->get_all_attributes(index_of_class);

        int index = 12;
        for(int i =0;i<vec.size();++i){
            if(vec[i] == basedName) break;
            index += 4;
        }
        
        emit_comment(out, std::string("Attribute loaded: ") + std::string(name));
        
        emit_load_word(out, ArgumentRegister{0},
            MemoryLocation{index, ArgumentRegister{0}});
        
        emit_empty_line(out);

        return;
    }
    if (auto artihmetic = dynamic_cast<const Arithmetic *>(expr)){
        emit_arithmetic(out, artihmetic);
        return;
    }
    if (auto parent = dynamic_cast<const ParenthesizedExpr *>(expr)){
        auto expr = parent->get_contents();
        emit_expr(out, expr);
        return;
    }

    if (auto ifelse = dynamic_cast<const IfThenElseFi *>(expr)){
        emit_if_else(out, ifelse);
        return;
    }
    
    if (auto in = dynamic_cast<const IntegerNegation *>(expr)){
        emit_integer_negation(out, in);
        return;
    }
    if (auto boolean = dynamic_cast<const BooleanNegation *>(expr)){
        emit_boolean_negation(out, boolean);
        return;
    }
    if (auto boolean = dynamic_cast<const BoolConstant *>(expr)){
        emit_bool_constant(out, boolean);
        return;
    }
    if (auto Int = dynamic_cast<const IntegerComparison *>(expr)){
        emit_integer_comparison(out, Int);
        return;
    }
    if (auto eqComp = dynamic_cast<const EqualityComparison *>(expr)){
        emit_equality_comparison(out, eqComp);
        return;
    }
    if (auto isVoid = dynamic_cast<const IsVoid *>(expr)){
        emit_is_void(out, isVoid);
        return;
    }
    if (auto let = dynamic_cast<const LetIn *>(expr)){
        // emit_comment(out, "LET ========");
        emit_let_in(out, let);
        return;
    }
    if (auto assign = dynamic_cast<const Assignment *>(expr)){
        // emit_comment(out, "LET ========");
        emit_assignment(out, assign);
        return;
    }
    if (auto object = dynamic_cast<const NewObject *>(expr)){
        emit_new_object(out, object);
        return;
    }
    if (auto loop = dynamic_cast<const WhileLoopPool *>(expr)){
        emit_while_loop_pool(out, loop);
        return;
    }


    // abort();
}
void ExpressionGenerator::emit_while_loop_pool(std::ostream &out, const WhileLoopPool *expr){
    
    count_loops++;
    emit_comment(out, "While loop");
    
    emit_comment(out, "Preserve self");
    emit_push_register(out, ArgumentRegister{0}); // preserve a0
    emit_empty_line(out);


    emit_expr(out, expr->get_condition()); // a0 is condition
    emit_empty_line(out);


    emit_comment(out, "Start loop");
    emit_branch_equal_zero(out, ArgumentRegister{0}, "while_loop_end" + std::to_string(count_loops));
    emit_empty_line(out);
    

    emit_pop_into_register(out, ArgumentRegister{0}); // load a0 again
    emit_push_register(out,ArgumentRegister{0}); //preserve a0 
    
    
    emit_label(out, "while_loop" + std::to_string(count_loops));


    emit_pop_into_register(out,ArgumentRegister{0});
    emit_push_register(out,ArgumentRegister{0}); //preserve a0

    emit_expr(out, expr->get_body()); // do something


    emit_pop_into_register(out,ArgumentRegister{0});
    emit_push_register(out,ArgumentRegister{0}); //preserve a0

    emit_expr(out, expr->get_condition()); // a0 is condition
    emit_empty_line(out);

    emit_load_word(out, ArgumentRegister{0}, MemoryLocation{12, ArgumentRegister{0}});
    
    emit_branch_greater_than_zero(out, ArgumentRegister{0}, "while_loop" + std::to_string(count_loops));
    
    
    emit_label(out, "while_loop_end" + std::to_string(count_loops));

    emit_pop_into_register(out, ArgumentRegister{0});
    emit_empty_line(out);
    // return self
}

void ExpressionGenerator::emit_new_object(std::ostream &out, const NewObject *expr){
    // out << "NEW Object\n";
    int type_id = expr->get_type();
    std::string name = std::string(class_table_->get_name(type_id));
    emit_comment(out, "New object: " + name);

    emit_push_register(out, FramePointer{});

    emit_load_address(out, ArgumentRegister{0}, name+"_protObj");
    
    emit_jump_and_link(out, "Object.copy");
    emit_push_register(out, FramePointer{});
    emit_jump_and_link(out, name+"_init");

    emit_empty_line(out);

}
void ExpressionGenerator::emit_assignment(std::ostream &out, const Assignment *expr){
    
    // out << "called assing-----====-------====-------====-------====-------====-------====-------====-------====-------====-------====--\n";
    std::string name = expr->get_assignee_name();
    emit_comment(out, "== assinging: " + name + " ==");

    emit_comment(out, "Push self");
    emit_push_register(out, ArgumentRegister{0}); // preserve self
    
    emit_comment(out, "compute value of element");
    emit_expr(out, expr->get_value()); // compute value to a0
    
    emit_comment(out, "Pop self");
    emit_pop_into_register(out, TempRegister{0}); // self is t0
    

    emit_comment(out, "Assing value");
    if (auto loc = lookup_local(name)) {
        emit_store_word(out, ArgumentRegister{0},
                    MemoryLocation{loc->fp_offset, FramePointer{}});
    }else{
        auto pos = name.find('_');
        std::string basedName = name.substr(0, pos);
        
        int index_of_class = class_table_->get_index(current_class);
        auto vec = class_table_->get_all_attributes(index_of_class);

        int index = 12;
        for(int i =0;i<vec.size();++i){
            if(vec[i] == basedName) break;
            index += 4;
        }
        emit_comment(out, std::string("Attribute loaded: ") + std::string(name));

        emit_store_word(out, ArgumentRegister{0},
            MemoryLocation{index, TempRegister{0}});
    }
    
    
    emit_move(out, ArgumentRegister{0}, TempRegister{0}); // return self to a0
    emit_empty_line(out);

}
void ExpressionGenerator::emit_vardecl(std::ostream &out, const Vardecl *expr){   
    
    emit_comment(out, "emit vardecl: " + expr->get_name());
    emit_empty_line(out);

    emit_comment(out, "save self");
    emit_push_register(out, ArgumentRegister{0});
    emit_empty_line(out);
    
    emit_comment(out, "initilizer");
    if(expr->has_initializer()){
        emit_expr(out, expr->get_initializer());  // init argument
    }else{
        emit_comment(out, "no init");
        // emit_move(out, ArgumentRegister{0}, ZeroRegister{}); // to add
        // init empty;
    }
    emit_empty_line(out);


    emit_comment(out, "reload self");
    emit_pop_into_register(out, TempRegister{0}); // self is t0
    emit_comment(out, "store value into stack");
    emit_store_word(out, ArgumentRegister{0}, {4,StackPointer{}}); // load varaible into argument

    emit_move(out, ArgumentRegister{0}, TempRegister{0}); // return self to a0

    emit_comment(out, "end of vardecl: " + expr->get_name());
    emit_empty_line(out);
    // return self
}

void ExpressionGenerator::emit_let_in(std::ostream &out, const LetIn *expr){
    
    emit_comment(out, "####################### entering scope #######################");
    push_scope();
    emit_comment(out, "Let env");
    emit_comment(out, "Store self");
    emit_push_register(out, ArgumentRegister{0});
    emit_comment(out, "Start let env");
    emit_push_register(out, FramePointer{});
    emit_move(out, FramePointer{}, StackPointer{});
    // // emit_push_register(out, FramePointer{});
    emit_empty_line(out);

    emit_comment(out, "== started setting variables == ");
    auto vardecls = expr->get_vardecls();
    for(auto vardecl : vardecls){
        emit_grow_stack(out, 1);

        int off = next_local_fp_offset_;
        next_local_fp_offset_ -= 4;

        emit_vardecl(out, vardecl);
        emit_empty_line(out);

        bind_local(vardecl->get_name(), LocalLoc{off});
    }
    emit_comment(out, "== end of settings varaibles ==");
    emit_empty_line(out);

    emit_comment(out, "Loading the self type in a0 again");
    emit_load_word(out, ArgumentRegister{0}, MemoryLocation{8, FramePointer{}});
    emit_empty_line(out);

    emit_comment(out, "Calling the - body - of let in ");
    emit_expr(out, expr->get_body());

    emit_empty_line(out);

    emit_comment(out, "####################### leaving scope #######################");
    pop_scope();
    int shrink_size = vardecls.size();
    emit_grow_stack(out, -(shrink_size));
    emit_empty_line(out);
    emit_comment(out, "restore framepointer");
    emit_pop_into_register(out, FramePointer{});
    emit_comment(out, "restore argumnet");
    emit_pop_into_register(out, ArgumentRegister{0});
    emit_empty_line(out);

}

void ExpressionGenerator::emit_is_void(std::ostream &out, const IsVoid *expr){
    
    emit_expr(out, expr->get_subject());

    count_comparison++;

    emit_branch_equal_zero(out, ArgumentRegister{0}, std::string("is_void") + std::to_string(count_comparison) );

    emit_add_immediate(out, TempRegister{1}, ZeroRegister{},0);

    emit_jump(out, std::string("is_void_end") + std::to_string(count_comparison));
    
    emit_label(out, std::string("is_void") + std::to_string(count_comparison));
    emit_add_immediate(out, TempRegister{1}, ZeroRegister{},1);

    emit_label(out, std::string("is_void_end") + std::to_string(count_comparison));

    emit_push_register(out, TempRegister{1});

    emit_comment(out, "Create bool const");
    emit_push_register(out, FramePointer{});
    emit_load_address(out, ArgumentRegister{0}, "Bool_protObj");    
    emit_jump_and_link(out, "Object.copy");

    // store value into Int.value (offset 12)
    emit_comment(out, "set value");
    emit_pop_into_register(out, TempRegister{1});
    emit_store_word(out, TempRegister{1},
                            MemoryLocation{12, ArgumentRegister{0}});
    emit_empty_line(out);

    //returns bool

}

void ExpressionGenerator::emit_method_invocation(std::ostream &out, const MethodInvocation *expr){
 
    emit_comment(out, "Method invocation");
    emit_push_register(out, ArgumentRegister{0});
    emit_push_register(out, FramePointer{});

    emit_empty_line(out);
    //add args
    emit_comment(out, "adding arguments to stack");
    auto args = expr->get_arguments();
    for (int i = args.size() - 1; i >= 0; --i) {
        emit_push_register(out, ArgumentRegister{0});
        
        emit_expr(out, args[i]);
        emit_pop_into_register(out, TempRegister{0});
        
        emit_push_register(out, ArgumentRegister{0});
        
        emit_move(out, ArgumentRegister{0},TempRegister{0});

        emit_empty_line(out);
    }
    
    //calls function
    // int cls = expr->get_static_dispatch_type();
    // std::string class_name = std::string(class_table_->get_name(cls));

    int index_of_class = class_table_->get_index(current_class);
    auto methods = class_table_->get_all_methods(index_of_class);

    emit_comment(out, "Calling body");
    for (auto& [mname, impl_cls] : methods) {
        std::string_view n = class_table_->get_name(impl_cls);
        if (mname == expr->get_method_name()) {
            emit_jump_and_link(out, std::string(n) + "." + expr->get_method_name());
        }
    }

    emit_empty_line(out);

    emit_comment(out, "returning the method data");

    emit_pop_into_register(out, ArgumentRegister{0});
}
void ExpressionGenerator::emit_dynamic_dispatch(std::ostream &out, const DynamicDispatch *expr){

    emit_push_register(out, ArgumentRegister{0});
    emit_push_register(out, FramePointer{});

    emit_empty_line(out);
    //add args
    auto args = expr->get_arguments();
    for (int i = args.size() - 1; i >= 0; --i) {
        emit_push_register(out, ArgumentRegister{0});
        
        emit_expr(out, args[i]);
        emit_pop_into_register(out, TempRegister{0});
        
        emit_push_register(out, ArgumentRegister{0});
        
        emit_move(out, ArgumentRegister{0},TempRegister{0});

        emit_empty_line(out);
    }
    
    //calls function
    // int cls = expr->get_static_dispatch_type();
    // std::string class_name = std::string(class_table_->get_name(cls));

    emit_comment(out, "CALLING SOMETHING!");
    auto target = expr->get_target();
    if(target){
        
        emit_expr(out, target);
        
        // int index_of_class = target->get_type();
        // auto methods = class_table_->get_all_methods(index_of_class);
        // for (auto& [mname, impl_cls] : methods) {
        //     std::string_view n = class_table_->get_name(impl_cls);
            // if (mname == expr->get_method_name()) {
            //     emit_jump_and_link(out, std::string(n) + "." + expr->get_method_name());
            // }
        // int index_of_class = class_table_->get_index(target->get_type());
        int index_of_class = target->get_type();
        int slot = class_table_->get_method_index(index_of_class, expr->get_method_name());
        // out << current_class << " " << expr->get_method_name() << " " << slot<< "\n" ;
        emit_load_word(out, TempRegister{0}, MemoryLocation{8, ArgumentRegister{0}});
        emit_load_word(out, TempRegister{0}, MemoryLocation{slot*4, TempRegister{0}});

        out <<"  jalr t0\n";
        // lw  t0, 8(a0)                   # t0 = dispatch table ptr
        // lw  t1, SLOT*4(t0)              # t1 = function addr for foo
        // jalr t1                         # call it (a0 is self)

        // }
    }else{   
        int index_of_class = class_table_->get_index(current_class);
        auto methods = class_table_->get_all_methods(index_of_class);
        for (auto& [mname, impl_cls] : methods) {
            std::string_view n = class_table_->get_name(impl_cls);
            if (mname == expr->get_method_name()) {
                emit_jump_and_link(out, std::string(n) + "." + expr->get_method_name());
            }
        }
    }
    // std::string class_name = std::string(class_table_->get_name();
    // emit_jump_and_link(out,  "IO." + expr->get_method_name());

    // emit_jump_and_link(out, "IO." + expr->get_method_name());

    emit_empty_line(out);
    emit_empty_line(out);

    emit_pop_into_register(out, ArgumentRegister{0});
    return;
}


void emit_object_reference(std::ostream &out, const ObjectReference *expr){

}
void ExpressionGenerator::emit_integer_comparison(std::ostream &out, const IntegerComparison *expr){

    count_comparison++;

    emit_expr(out,expr->get_lhs());


    emit_load_word(out, TempRegister{1},
        MemoryLocation{12, ArgumentRegister{0}});
        
    emit_push_register(out, TempRegister{1}); // lhs


    emit_expr(out,expr->get_rhs());

    emit_load_word(out, TempRegister{1},
                MemoryLocation{12, ArgumentRegister{0}});

    emit_push_register(out, TempRegister{1}); //rhs
    

        
    emit_push_register(out, FramePointer{});

    emit_load_address(out, ArgumentRegister{0}, "Int_protObj");
    
    emit_jump_and_link(out, "Object.copy");

    // store value into Int.value (offset 12)

    emit_pop_into_register(out, TempRegister{1});
    emit_pop_into_register(out, TempRegister{0});


    IntegerComparison::Kind kind = expr->get_kind();

    emit_subtract(out, TempRegister{2}, TempRegister{0},TempRegister{1});
    
    if(kind == IntegerComparison::Kind::LessThan){
        emit_branch_greater_than_zero(out, TempRegister{2},
        std::string("int_comp_false") + std::to_string(count_comparison));
        emit_branch_equal_zero(out, TempRegister{2},
        std::string("int_comp_false") + std::to_string(count_comparison));
    }else if (kind == IntegerComparison::Kind::LessThanEqual){
        emit_branch_greater_than_zero(out, TempRegister{2},
        std::string("int_comp_false") + std::to_string(count_comparison));
    }

    emit_label(out, std::string("int_comp_true") + std::to_string(count_comparison));
    emit_add_immediate(out, TempRegister{2}, ZeroRegister{},1 );
    emit_jump(out, std::string("int_comp_exit") + std::to_string(count_comparison));

    
    emit_label(out, std::string("int_comp_false") + std::to_string(count_comparison));
    emit_add_immediate(out, TempRegister{2}, ZeroRegister{},0);

    
    emit_label(out, std::string("int_comp_exit") + std::to_string(count_comparison));
    


    emit_store_word(out, TempRegister{2},
                MemoryLocation{12, ArgumentRegister{0}});

    // return bool
}

void ExpressionGenerator::emit_boolean_negation(std::ostream &out, const BooleanNegation *expr){

    emit_comment(out, "Reverse bool");
    emit_expr(out, expr->get_argument());
    
    emit_load_word(out, TempRegister{1},
                    MemoryLocation{12, ArgumentRegister{0}});

    emit_add_immediate(out, TempRegister{0}, ZeroRegister{}, 1); // a0 = 1

    emit_comment(out, "reverse the value");
    emit_subtract(out, TempRegister{1}, TempRegister{0}, TempRegister{1});

    emit_comment(out, "save back");
    emit_store_word(out, TempRegister{1}, MemoryLocation{12, ArgumentRegister{0}});
    emit_empty_line(out);

    // return bool
}
void ExpressionGenerator::emit_integer_negation(std::ostream &out, const IntegerNegation *expr){

    emit_comment(out, "Reverse int");
    emit_expr(out, expr->get_argument());

    emit_load_word(out, TempRegister{1},
                MemoryLocation{12, ArgumentRegister{0}});

    emit_comment(out, "reverse the value");
    emit_subtract(out, TempRegister{1}, ZeroRegister{}, TempRegister{1});

    emit_comment(out, "save back");
    emit_store_word(out, TempRegister{1}, MemoryLocation{12, ArgumentRegister{0}});

    emit_empty_line(out);
    // return int

}
void ExpressionGenerator::emit_bool_constant(std::ostream &out, const BoolConstant *expr){
    
    emit_comment(out, "Create bool const");
    emit_push_register(out, FramePointer{});

    emit_load_address(out, ArgumentRegister{0}, "Bool_protObj");    
    emit_jump_and_link(out, "Object.copy");

    // store value into Int.value (offset 12)
    emit_comment(out, "set value");
    emit_add_immediate(out, TempRegister{0}, ZeroRegister{},
                            expr->get_value() ? 1 : 0);
    emit_store_word(out, TempRegister{0},
                            MemoryLocation{12, ArgumentRegister{0}});
    emit_empty_line(out);

    // return bool

}
void ExpressionGenerator::emit_equality_comparison(std::ostream &out, const EqualityComparison *expr){
    
    emit_comment(out, "Start equality comparison");
    
    count_comparison++;

    bool its_string = false;
        
    if (auto obj = dynamic_cast<const ObjectReference *>(expr->get_lhs())) {
        std::string name = obj->get_name();
        
        int index_of_class = class_table_->get_index("Main");
        int string_ty = class_table_->get_index("String");

        if(class_table_->get_attribute_type(index_of_class, name) == string_ty){
            its_string = true;
        }
    }

    if (auto obj = dynamic_cast<const StringConstant *>(expr->get_lhs())) {
        its_string = true;
    }


    if(its_string){
        
        emit_comment(out, "compute lhs");
        emit_push_register(out, ArgumentRegister{0}); // save self
        emit_expr(out,expr->get_lhs());
        emit_pop_into_register(out, TempRegister{0}); // load self
        
        emit_push_register(out, ArgumentRegister{0}); // put lhs inside stack
        emit_move(out, ArgumentRegister{0}, TempRegister{0}); // move self

        
        emit_comment(out, "compute rhs");
        emit_push_register(out, ArgumentRegister{0}); // put lhs inside stack
        emit_expr(out,expr->get_rhs());
        emit_pop_into_register(out, TempRegister{0}); // load self
        
        emit_push_register(out, ArgumentRegister{0}); // put rhs inside stack
        emit_move(out, ArgumentRegister{0}, TempRegister{0}); // move self
        

        emit_comment(out, "get values from stack for rhs and lhs");
        emit_pop_into_register(out, TempRegister{0}); // rhs 
        emit_pop_into_register(out, TempRegister{1}); // lhs 


        // emit_load_word(out, TempRegister{0},
        //             MemoryLocation{12, TempRegister{0}});
    
        // emit_load_word(out, TempRegister{1},
        //             MemoryLocation{12, TempRegister{1}});

        // emit_load_word(out, TempRegister{0},
        //             MemoryLocation{12, TempRegister{0}});
    
        // emit_load_word(out, TempRegister{1},
        //             MemoryLocation{12, TempRegister{1}});
    
                    
        emit_comment(out, "Start comparison");
        emit_subtract(out, TempRegister{4}, TempRegister{1}, TempRegister{0});
        emit_branch_equal_zero(out, TempRegister{4}, "equal_compr"+ std::to_string(count_comparison));
        emit_empty_line(out);
        
        emit_comment(out, "if not equal");
        emit_add_immediate(out, TempRegister{5}, ZeroRegister{}, 0); // false
        emit_jump(out, "equal_compr_exit" + std::to_string(count_comparison));
        emit_empty_line(out);
        
        emit_comment(out, "if equal");
        emit_label(out, "equal_compr" + std::to_string(count_comparison));
        emit_add_immediate(out, TempRegister{5}, ZeroRegister{}, 1); // false
        emit_empty_line(out);
        
        
        emit_comment(out, "leaving");
        
        emit_label(out, "equal_compr_exit" + std::to_string(count_comparison));
        
    }else{

        emit_comment(out, "compute lhs");
        emit_expr(   out,expr->get_lhs());
        
        emit_push_register(out, ArgumentRegister{0}); // put lhs inside stack
        
        emit_comment(out, "compute rhs");
        emit_expr(out,expr->get_rhs());
        
        emit_push_register(out, ArgumentRegister{0}); // put rhs inside stack
        
        
        emit_comment(out, "get values from stack for rhs and lhs");
        emit_pop_into_register(out, TempRegister{0}); // rhs 
        emit_pop_into_register(out, TempRegister{1}); // lhs 
        
        emit_load_word(out, TempRegister{3},
                        MemoryLocation{12, TempRegister{0}});
        
        emit_load_word(out, TempRegister{2},
                        MemoryLocation{12, TempRegister{1}});

                        
                        
        emit_comment(out, "Start comparison");
        emit_subtract(out, TempRegister{4}, TempRegister{3}, TempRegister{2});
        emit_branch_equal_zero(out, TempRegister{4}, "equal_compr"+ std::to_string(count_comparison));
        emit_empty_line(out);
        
        emit_comment(out, "if not equal");
        emit_add_immediate(out, TempRegister{5}, ZeroRegister{}, 0); // false
        emit_jump(out, "equal_compr_exit" + std::to_string(count_comparison));
        emit_empty_line(out);
        
        emit_comment(out, "if equal");
        emit_label(out, "equal_compr" + std::to_string(count_comparison));
        emit_add_immediate(out, TempRegister{5}, ZeroRegister{}, 1); // false
        emit_empty_line(out);
        
        
        emit_comment(out, "leaving");
        
        emit_label(out, "equal_compr_exit" + std::to_string(count_comparison));
        
    }

    emit_comment(out, "Create bool");
    emit_push_register(out, FramePointer{});

    emit_load_address(out, ArgumentRegister{0}, "Bool_protObj");
    emit_jump_and_link(out, "Object.copy");
    emit_empty_line(out);
    
    emit_store_word(out, TempRegister{5},
                MemoryLocation{12, ArgumentRegister{0}});
    emit_empty_line(out);    
    
    
    // emit_comment(out, "Create bool const");
    // emit_push_register(out, FramePointer{});
    
    // emit_load_address(out, ArgumentRegister{0}, "Bool_protObj");    
    // emit_jump_and_link(out, "Object.copy");
    
    // // store value into Int.value (offset 12)
    // emit_comment(out, "set value");
    // emit_add_immediate(out, TempRegister{0}, ZeroRegister{}, 1);
    // emit_store_word(out, TempRegister{0}, MemoryLocation{12, ArgumentRegister{0}});
    // emit_empty_line(out);
    
    
    
    // return bool
}


void ExpressionGenerator::emit_if_else(std::ostream &out, const IfThenElseFi *expr){
    int local_count = ++count_ifs_;

    emit_comment(out, "store self class");
    emit_push_register(out, ArgumentRegister{0});
    emit_empty_line(out);

    emit_comment(out, "compute condition");
    emit_expr(out, expr->get_condition());
    emit_empty_line(out);


    emit_comment(out, "branching");

    emit_load_word(out, TempRegister{1},
                MemoryLocation{12, ArgumentRegister{0}});
    emit_pop_into_register(out, ArgumentRegister{0});
    
    emit_branch_equal_zero(out, TempRegister{1}, std::string("if_else") + std::to_string(local_count));
    emit_empty_line(out);
    
    emit_comment(out, "if true");
    emit_expr(out, expr->get_then_expr());    
    emit_jump(out, std::string("if_exit") + std::to_string(local_count));    

    emit_comment(out, "if false");
    emit_label(out, std::string("if_else") + std::to_string(local_count));
    emit_expr(out, expr->get_else_expr());

    emit_comment(out, "exiting");
    emit_label(out, std::string("if_exit") + std::to_string(local_count)); 
  
    emit_comment(out, "reseting default value for class");
    // emit_pop_into_register(out, ArgumentRegister{0});
    emit_empty_line(out);
    // return Class
}

void ExpressionGenerator::emit_arithmetic(std::ostream &out, const Arithmetic *expr){

    emit_comment(out, "start arithmetics");
    emit_empty_line(out);
    emit_comment(out, " compute lhs");
    emit_expr(out, expr->get_lhs());

    emit_comment(out, " store value from lhs");    
    emit_load_word(out, TempRegister{1},
        MemoryLocation{12, ArgumentRegister{0}});
        
    emit_push_register(out, TempRegister{1});
    
    emit_empty_line(out);
        
    emit_comment(out, " compute rhs");
    emit_expr(out,expr->get_rhs());


    emit_comment(out, " store value from rhs");
    emit_load_word(out, TempRegister{1},
                MemoryLocation{12, ArgumentRegister{0}});

    emit_push_register(out, TempRegister{1}); //rhs

    emit_empty_line(out);
    
   
    emit_comment(out, "Start computing final value");
        
    emit_push_register(out, FramePointer{});

    emit_load_address(out, ArgumentRegister{0}, "Int_protObj");
    
    emit_jump_and_link(out, "Object.copy");

    // store value into Int.value (offset 12)

    emit_pop_into_register(out, TempRegister{1});
    emit_pop_into_register(out, TempRegister{0});

    Arithmetic::Kind kind = expr->get_kind();

    if(kind == Arithmetic::Kind::Addition){
        emit_add(out, TempRegister{2}, TempRegister{0},TempRegister{1});
    }else if(kind == Arithmetic::Kind::Subtraction){
        emit_subtract(out, TempRegister{2}, TempRegister{0},TempRegister{1});
    }else if(kind == Arithmetic::Kind::Multiplication){
        emit_multiply(out, TempRegister{2}, TempRegister{0},TempRegister{1});
    }else if(kind == Arithmetic::Kind::Division){
        emit_divide(out, TempRegister{2}, TempRegister{0},TempRegister{1});
    }

    emit_comment(out, "Store and return value");
    emit_store_word(out, TempRegister{2},
                MemoryLocation{12, ArgumentRegister{0}});

    emit_empty_line(out);
    // return INT_CONST
}


void ExpressionGenerator::emit_static_dispatch(std::ostream &out, const StaticDispatch *expr){

    emit_push_register(out, ArgumentRegister{0});
    emit_push_register(out, FramePointer{});

    emit_empty_line(out);
    //add args
    auto args = expr->get_arguments();
    for (int i = args.size() - 1; i >= 0; --i) {
        emit_push_register(out, ArgumentRegister{0});
        
        emit_expr(out, args[i]);
        emit_pop_into_register(out, TempRegister{0});
        
        emit_push_register(out, ArgumentRegister{0});
        
        emit_move(out, ArgumentRegister{0},TempRegister{0});

        emit_empty_line(out);
    }
    
    //calls function
    int cls = expr->get_static_dispatch_type();
    std::string class_name = std::string(class_table_->get_name(cls));
    emit_jump_and_link(out, class_name + "." + expr->get_method_name());

    emit_empty_line(out);
    emit_empty_line(out);

    emit_pop_into_register(out, ArgumentRegister{0});
    return;
    // return CLASS
}
void ExpressionGenerator::emit_string_constant(std::ostream &out, const StringConstant *expr){
    emit_comment(out, "loads string");
    int id = string_table.get_id(expr->get_value());
    std::string label = "_string" + std::to_string(id) + ".content";
    emit_load_address(
        out,
        ArgumentRegister{0},
        label
    );
    emit_empty_line(out);
    // return STIRNG
}
void ExpressionGenerator::emit_int_constant(std::ostream &out, const IntConstant *expr){
   // a0 = new Int object


    emit_comment(out, "new int(" + std::to_string(expr->get_value()) + ")");
    emit_push_register(out, FramePointer{});

    emit_load_address(out, ArgumentRegister{0}, "Int_protObj");
    
    emit_jump_and_link(out, "Object.copy");
    
    emit_push_register(out, FramePointer{});
    emit_jump_and_link(out, "Int_init");

    // store value into Int.value (offset 12)
    emit_add_immediate(out, TempRegister{0}, ZeroRegister{}, expr->get_value());
    emit_store_word(out, TempRegister{0},
                MemoryLocation{12, ArgumentRegister{0}});
    emit_empty_line(out);


    // return INT
}