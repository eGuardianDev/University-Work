#ifndef CODEGEN_COOL_CODEGEN_H_
#define CODEGEN_COOL_CODEGEN_H_

#include <memory>
#include <ostream>

#include "CoolParser.h"
#include "semantics/ClassTable.h"

#include "StringTable.h"

#include "codegen/ExpressionGenerator.h"

class CoolCodegen {
  private:

    std::string file_name_;
    StringTable string_table_;
    std::unique_ptr<ClassTable> class_table_;
    void emit_dispatch_tables(std::ostream& out);
    void emit_init_methods(std::ostream& out,ExpressionGenerator &eg);
    void emit_class_object_table(std::ostream &out);
    void emit_name_table_of_classes(std::ostream &out);
    void emit_string_constants(std::ostream &out);
    void emit_prototype_objects(std::ostream &out);
    
    void emit_functions(std::ostream &out, ExpressionGenerator &eg);



  bool is_builtin_class (int cls) {
      std::string_view n = class_table_->get_name(cls);
      return n == "Object" || n == "IO" || n == "Int" || n == "Bool" || n == "String";
  };

  // Returns method names (unique) that are implemented by user classes.
  std::vector<std::string> get_user_defined_methods() {
      std::unordered_set<std::string> seen;
      std::vector<std::string> out;

      for (int c = 0; c < class_table_->get_num_of_classes(); ++c) {
          if (is_builtin_class(c)) continue; // only user classes

          // methods available on c, with the class that actually implements each one
          auto methods = class_table_->get_all_methods(c);

          for (auto& [mname, impl_cls] : methods) {
              if (is_builtin_class(impl_cls)) continue; // skip built-in implementations

              if (seen.insert(mname).second) {
                  out.push_back(mname);
              }
          }
      }
      return out;
  }

  public:
    CoolCodegen(std::string file_name, std::unique_ptr<ClassTable> class_table)
        : file_name_(std::move(file_name)),
          class_table_(std::move(class_table)) {}

    void generate(std::ostream &out);


};

#endif
