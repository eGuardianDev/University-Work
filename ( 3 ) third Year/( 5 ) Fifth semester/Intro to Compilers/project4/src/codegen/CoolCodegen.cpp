#include "CoolCodegen.h"

#include "codegen/ExpressionGenerator.h"

using namespace std;
// using namespace
using namespace riscv_emit;

void CoolCodegen::emit_name_table_of_classes(std::ostream& out){
    
    emit_p2align(out, 2);
    emit_globl(out, "class_nameTab");
    emit_label(out, "class_nameTab");
    // Safer: emit 6 entries because runtime assumes base classes + Main.
    // emit_word(out, "Object_className");
    // emit_word(out, "IO_className");
    // emit_word(out, "Int_className");
    // emit_word(out, "Bool_className");
    // emit_word(out, "String_className");
    // emit_word(out, "Main_className");
    for(auto classes : class_table_->get_class_names()){
        emit_word(out, classes + "_className");
    }

    emit_gc_tag(out);
    emit_label(out, "Object_classNameLength");
    emit_word(out,2); // class tag
    emit_word(out,4); // object size
    emit_word(out,"Int_dispTab"); // dispatch table
    emit_word(out,6); // first attribute
    
    emit_empty_line(out);
    
    emit_gc_tag(out);
    emit_label(out, "Object_className");
    emit_word(out,4); // class tag
    emit_word(out,6); // object size
    emit_word(out,"String_dispTab");
    emit_word(out,"Object_classNameLength");
    emit_string(out, "Object");
    emit_byte(out, 0);  

    emit_empty_line(out);

    emit_gc_tag(out);
    emit_label(out, "IO_classNameLength");
    emit_word(out,2); // class tag
    emit_word(out,4); // object size
    emit_word(out,"Int_dispTab"); // dispatch table
    emit_word(out,2); // first attribute
    
    emit_empty_line(out);
    
    emit_gc_tag(out);
    emit_label(out, "IO_className");
    emit_word(out,4); // class tag
    emit_word(out,5); // object size
    emit_word(out,"String_dispTab");
    emit_word(out,"IO_classNameLength");
    emit_string(out, "IO");
    emit_byte(out, 0);

    emit_empty_line(out);


    emit_gc_tag(out);
    emit_label(out, "Int_classNameLength");
    emit_word(out,2); // class tag
    emit_word(out,4); // object size
    emit_word(out,"Int_dispTab"); // dispatch table
    emit_word(out,3); // first attribute
    
    emit_empty_line(out);
    
    emit_gc_tag(out);
    emit_label(out, "Int_className");
    emit_word(out,4); // class tag
    emit_word(out,5); // object size
    emit_word(out,"String_dispTab");
    emit_word(out,"Int_classNameLength");
    emit_string(out, "Int");

    emit_empty_line(out);


    emit_gc_tag(out);
    emit_label(out, "Bool_classNameLength");
    emit_word(out,2); // class tag
    emit_word(out,4); // object size
    emit_word(out,"Int_dispTab"); // dispatch table
    emit_word(out,4); // first attribute
    
    emit_empty_line(out);
    
    emit_gc_tag(out);
    emit_label(out, "Bool_className");
    emit_word(out,4); // class tag
    emit_word(out,5); // object size
    emit_word(out,"String_dispTab");
    emit_word(out,"Bool_classNameLength");
    emit_string(out, "Bool");
    emit_byte(out, 0);
    emit_byte(out, 0);
    emit_byte(out, 0);

    emit_empty_line(out);


    emit_gc_tag(out);
    emit_label(out, "String_classNameLength");
    emit_word(out,2); // class tag
    emit_word(out,4); // object size
    emit_word(out,"Int_dispTab"); // dispatch table
    emit_word(out,6); // first attribute
    
    emit_empty_line(out);
    
    emit_gc_tag(out);
    emit_label(out, "String_className");
    emit_word(out,4); // class tag
    emit_word(out,6); // object size
    emit_word(out,"String_dispTab");
    emit_word(out,"String_classNameLength");
    emit_string(out, "String");
    emit_byte(out, 0);

    emit_empty_line(out);


    emit_gc_tag(out);
    emit_label(out, "Main_classNameLength");
    emit_word(out,2); // class tag
    emit_word(out,4); // object size
    emit_word(out,"Int_dispTab"); // dispatch table
    emit_word(out,4); // first attribute (string name)

    
    emit_empty_line(out);
    
    emit_gc_tag(out);
    emit_label(out, "Main_className");
    emit_word(out,4); // class tag
    emit_word(out,6); // object size
    emit_word(out,"String_dispTab");
    emit_word(out,"Main_classNameLength");
    emit_string(out, "Main");
    emit_byte(out, 0);

    emit_empty_line(out);



    auto emit_name_and_len = [&](const std::string& name) {
        emit_gc_tag(out);
        emit_label(out, name+"_classNameLength");
        emit_word(out,2); // class tag
        emit_word(out,4); // object size
        emit_word(out,"Int_dispTab"); // dispatch table
        emit_word(out,4); // first attribute (string name)

        
        emit_empty_line(out);
        
        emit_gc_tag(out);
        emit_label(out, name+"_className");
        emit_word(out,4); // class tag
        int bytes = (int)name.size() + 1;          // include '\0'
        int payload_words = (bytes + 3) / 4;       // ceil(bytes/4)
        int size = 4 + payload_words;     
        emit_word(out,size); // object size
        emit_word(out,"String_dispTab");
        emit_word(out,name+"_classNameLength");
        emit_string(out, name);
        emit_byte(out, 0);

        emit_empty_line(out);
    };

    for(auto classes : class_table_->get_class_names()){
        if(!(classes == "Object"|| classes == "Main" || classes == "String" || classes == "IO" || classes == "Int" || classes == "Bool")){
            emit_name_and_len(classes);
        }
    }
}

void CoolCodegen::emit_dispatch_tables(std::ostream& out) {

    auto emit_table = [&](const std::string& name) {
        emit_globl(out, name + "_dispTab");
        emit_label(out, name + "_dispTab");
        int index_of_class = class_table_->get_index(name);
        auto vec = class_table_->get_all_methods(index_of_class);
        for(auto& [method, impl_class] : vec){
            std::string impl = std::string(class_table_->get_name(impl_class));
            emit_word(out, impl + "." + method);
        }
        emit_empty_line(out);
    };

    for(auto classes : class_table_->get_class_names()){
        emit_table(classes);
    }

}
void CoolCodegen::emit_init_methods(std::ostream& out, ExpressionGenerator &eg){

    auto emit_body = [&](const std::string& name) {

        emit_globl(out, name);
        emit_label(out, name);

        emit_move(out, FramePointer{}, StackPointer{});
        // emit_add(out, FramePointer{}, StackPointer{}, );
        // emit_move(out, FramePointer{}, StackPointer{});
        emit_store_word(out, ReturnAddress{}, MemoryLocation{0, StackPointer{}});
        emit_grow_stack(out, 1);
        emit_empty_line(out);




        auto pos = name.find('_');
        std::string basedName = name.substr(0, pos);

        int index_of_class = class_table_->get_index(basedName);
        auto vec = class_table_->get_all_attributes(index_of_class);
        
        int index = 12;
        
        for(auto attr : vec){
            emit_comment(out, std::string("Attribute: ") + std::string(attr));
            auto initExpr = class_table_->transitive_get_attribute_initializer(basedName,attr); 

            emit_push_register(out, ArgumentRegister{0}); // save self

            emit_empty_line(out);

            if(initExpr){
                eg.emit_expr(out, initExpr); // get new expr, will be in a0
            }else{
                // emit_set_equal_zero(out, ArgumentRegister{0}, ArgumentRegister{0});
                // emit_add_immediate(out, ArgumentRegister{0}, ZeroRegister{}, 0);
                emit_move(out, ArgumentRegister{0}, ZeroRegister{});
                
            }

            emit_pop_into_register(out, TempRegister{0}); // access self
            emit_store_word(out, ArgumentRegister{0}, MemoryLocation{index, {TempRegister{0}}});
            

            emit_move(out, ArgumentRegister{0},TempRegister{0});
            index +=4;
            emit_empty_line(out);
        }


        if(vec.size() ==0){

            if(name == "Int"){
                emit_comment(out, "Initializing INT");
                emit_push_register(out, TempRegister{0});
                emit_set_equal_zero(out, TempRegister{0}, TempRegister{0});
                emit_store_word(out, TempRegister{0}, {12,ArgumentRegister{0}});
                emit_pop_into_register(out, TempRegister{0});
            }
            else if(name== "Bool")
            {
                emit_comment(out, "Initializing BOOL");
                emit_push_register(out, TempRegister{0});
                emit_set_equal_zero(out, TempRegister{0}, TempRegister{0});
                emit_store_word(out, TempRegister{0}, {12,ArgumentRegister{0}});
                emit_pop_into_register(out, TempRegister{0});
            }
            else if(name== "IO" || name == "Object")
            {
                emit_comment(out, "No op");
            }
            else if(name== "String")
            {
                emit_comment(out, "No op");
            }
            else
            {
                emit_comment(out, "No op");
            }

        }



        emit_empty_line(out);
        emit_load_word(out, ReturnAddress{}, MemoryLocation{0, FramePointer{}});
        emit_grow_stack(out, -2);
        emit_load_word(out, FramePointer{}, MemoryLocation{0, StackPointer{}});

        emit_empty_line(out);
        
        emit_mnemonic(out, Mnemonic::Return);


        emit_empty_line(out);
    };


    emit_text_segment_tag(out);
    
    
    // emit_body("Object_init");
    // out << "\n";

    // emit_body("IO_init");
    // out << "\n";

    // emit_body("Int_init");
    // out << "\n";

    // emit_body("Bool_init");
    // out << "\n";

    // emit_body("String_init");
    // out << "\n";

    // emit_body("Main_init");
    // out << "\n";


    for(auto classes : class_table_->get_class_names()){
        emit_body(classes + "_init");
        emit_empty_line(out);
    }
}

void CoolCodegen::emit_class_object_table(std::ostream &out){

    emit_data_segment_tag(out);
    emit_label(out,"class_objTab");

    for(auto classes : class_table_->get_class_names()){
        emit_word(out, classes+ "_protObj");
        emit_word(out, classes+ "_init");
    }

    emit_globl(out,"_bool_tag");
    emit_label(out,"_bool_tag");
    emit_word(out,3);

    emit_globl(out,"_int_tag");
    emit_label(out,"_int_tag");
    emit_word(out,2);
    
    emit_globl(out,"_string_tag");
    emit_label(out,"_string_tag");
    emit_word(out,4);


}

void CoolCodegen::emit_string_constants(ostream &out){


    for(auto [a,b] : string_table_.all()){
        emit_p2align(out,2);
        emit_gc_tag(out);
        emit_label(out, std::string("_string") + std::to_string(b) + ".length");
        emit_word(out,2);
        emit_word(out,4);
        emit_word(out,0);

        int size = a.size()-2;

        for(int i =0;i<a.size()-1;++i){
            if(a[i]=='\\'){
                ++i;
                if(a[i]== 'n' || a[i]=='r' ||
                a[i] == 't'){
                    --size;
                }
            }
        }

        emit_word(out, size);
        
        emit_empty_line(out);
        
        emit_gc_tag(out);
        emit_label(out, std::string("_string") + std::to_string(b) + ".content");
        emit_word(out,4);
        int size_words = (16 + (size + 1) + 3) / 4;
        emit_word(out,size_words);
        emit_word(out,"String_dispTab");
        emit_word(out, std::string("_string") + std::to_string(b) + ".length");
        emit_string(out, a.substr(1,a.size()-2));
        emit_byte(out, 0);
        // emit_byte(out, 0);
        
        emit_empty_line(out);
    
    }
}

void CoolCodegen::emit_functions(std::ostream &out, ExpressionGenerator &eg){
  
    auto emit_function= [&](const std::string& name, const std::string &func){

        emit_globl(out, name + "." + func);
        emit_label(out, name + "." + func);

        emit_empty_line(out);

        emit_comment(out,"prologue");

        //setup ready
        emit_move(out, FramePointer{}, StackPointer{});
        emit_push_register(out, ReturnAddress{});
        emit_empty_line(out);

        eg.current_class = name;

        eg.current_function = func;
        
        int index_of_class = class_table_->get_index(name);
        const Expr* main_body =
            class_table_->get_method_body(index_of_class, func);
        
        eg.emit_expr(out, main_body);
        emit_empty_line(out);



        emit_comment(out,"epilogue");
        
        emit_load_word(out, ReturnAddress{}, MemoryLocation{0, FramePointer{}});
        emit_grow_stack(out, -1); // remove ra

        //remove args
        int argc = (int)class_table_->get_argument_names(index_of_class, func).size();

        emit_grow_stack(out, -(argc));

        // emit_load_word(out, FramePointer{}, MemoryLocation{0, StackPointer{}});
        // emit_grow_stack(out, -(argc));
        emit_pop_into_register(out, FramePointer{});
        emit_mnemonic(out, Mnemonic::Return);
        emit_empty_line(out);
        
        emit_comment(out," === end of "+name+"."+func+" === ");
        
    };
    
    emit_comment(out, "CLASSES =======================================================");
    for (int c = 0; c < class_table_->get_num_of_classes(); ++c) {
        if (is_builtin_class(c)) continue;

        auto methods = class_table_->get_all_methods(c);
        for (auto& [mname, impl_cls] : methods) {
            if (impl_cls != c) continue; // only methods implemented by this class
            // (c.mname) is user-defined and you should emit its body
            // out << mname << "\n";
            emit_function(std::string(class_table_->get_name(impl_cls)), mname);
        }
    }

}


void CoolCodegen::emit_prototype_objects(std::ostream &out){
emit_p2align(out, 2);
    auto emit_prot3 = [&](const std::string& name, int tag,
                          const std::string& disp) {
        emit_gc_tag(out);
        emit_globl(out, name);
        emit_label(out, name);
        emit_word(out, tag); // tag
        auto pos = name.find('_');
        std::string basedName = name.substr(0, pos);

        int index_of_class = class_table_->get_index(std::string(basedName));
        auto vec = class_table_->get_all_attributes(index_of_class);
        
        int size = 3+vec.size();
        
        // emit_word(out, 3);   // size
        emit_word(out, size);   // size
        emit_word(out, disp);   // disp

        for(auto attr : vec){
            emit_comment(out, std::string("Attribute: ") + std::string(attr));
            emit_word(out, 0);
        }

        emit_empty_line(out);
    };


    emit_prot3("Object_protObj", 0, "Object_dispTab");
    emit_prot3("IO_protObj",     1, "IO_dispTab");

    emit_gc_tag(out);
    emit_globl(out, "Int_protObj");
    emit_label(out, "Int_protObj");
    emit_word(out, 2); // class tag
    emit_word(out, 4); // object size
    emit_word(out, "Int_dispTab"); // dispatch table
    emit_word(out, 0); // first attribute
    emit_empty_line(out);

    emit_gc_tag(out);
    emit_globl(out, "Bool_protObj");
    emit_label(out, "Bool_protObj");
    emit_word(out, 3); // class tag
    emit_word(out, 4); // object size
    emit_word(out, "Bool_dispTab"); // dispatch table
    emit_word(out, 0); // first attribute
    emit_empty_line(out);

    emit_gc_tag(out);
    emit_globl(out, "String_protObj");
    emit_label(out, "String_protObj");
    emit_word(out, 4); // class tag
    emit_word(out, 5); // object size
    emit_word(out, "String_dispTab");
    emit_word(out, 0); // first attribute; size of string
    emit_word(out, 0); // second attribute; terminating char 0 
    emit_empty_line(out);


    int i = 5;
    for(auto classes : class_table_->get_class_names()){
        if(!(classes == "Object"|| classes == "String" || classes == "IO" || classes == "Int" || classes == "Bool")){
            emit_prot3(classes+"_protObj",   i /*class_table_->get_index(classes)*/, classes+"_dispTab");
            ++i;
        }
    }
    
}


void CoolCodegen::generate(ostream &out) {

    // 1. create an "object model class table" that uses the class_table_ to compute the layout of objects in memory

    /*
        .text 
    */
    emit_text_segment_tag(out);
    
    emit_empty_line(out);

    emit_label(out,"_inf_loop");
    emit_jump(out,"_inf_loop");
    emit_empty_line(out);
    /*
        Main program
    */
    // emit_globl(out, "Main.main");
    // emit_label(out, "Main.main");


    // /*
    //     start function
    // */
    // emit_empty_line(out);

    // emit_comment(out,"prologue");

    // // emit_grow_stack(out,2);
    // // emit_store_word(out, FramePointer{}, MemoryLocation{0, StackPointer{}});
    // // emit_store_word(out, ReturnAddress{}, MemoryLocation{4, StackPointer{}});
    // // emit_add_immediate(out, FramePointer{}, StackPointer{}, 0);


    // //setup ready
    // emit_move(out, FramePointer{}, StackPointer{});
    // emit_push_register(out, ReturnAddress{});
    // emit_empty_line(out);

    
    



    // emit_comment(out,"code inside main:");
    // /*
    //     Start main function
    // */
    // int index_of_main = class_table_->get_index("Main");
    // const Expr* main_body =
    //     class_table_->get_method_body(index_of_main, "main");


    ExpressionGenerator eg(class_table_.get());

    // eg.current_class = "Main";

    // eg.emit_expr(out,main_body);


    // string_table_ = eg.get_string_table();


    // emit_empty_line(out);

    // emit_comment(out,"epilogue");
    
    // emit_load_word(out, ReturnAddress{}, MemoryLocation{0, FramePointer{}});
    // emit_grow_stack(out, -1);
    // emit_load_word(out, FramePointer{}, MemoryLocation{0, StackPointer{}});
    // emit_mnemonic(out, Mnemonic::Return);
    // emit_empty_line(out);
    
    // emit_comment(out," === end of Main.main === ");

    //emit others
    emit_functions(out, eg);

    string_table_ = eg.get_string_table();

    emit_data_segment_tag(out);
    emit_comment(out,"------------- Name table of classes ------------------------------------------");
    
    emit_name_table_of_classes(out);

    
    emit_comment(out,"------------- Prototype objects ----------------------------------------------");
    emit_prototype_objects(out);


    emit_comment(out,"------------- Dispatch tables ------------------------------------------------");

    emit_dispatch_tables(out);

    emit_comment(out,"----------------- Init methods -----------------------------------------------");

    emit_init_methods(out,eg);
    string_table_ = eg.get_string_table();

    emit_comment(out,"------------- Class object table ---------------------------------------------");

    emit_class_object_table(out);

    emit_comment(out,"------------- Constants ---------------------------------------------");

    emit_string_constants(out);


    // 2. create a class to contain static constants (to be emitted at the end)
    
    // 3. emit code for method bodies; possibly append to static constants
    
    // 4. emit prototype objects
    
    // 5. emit dispatch tables
    
    // 6. emit initialization methods for classes
    
    // 7. emit class name table
    
    // 8. emit static constants
    
    // Extra tip: implement code generation for expressions in a separate class and reuse it for method impls and init methods.
    
    
    // The following is an example manually written assembly that prints out "hello, world".
}
    
