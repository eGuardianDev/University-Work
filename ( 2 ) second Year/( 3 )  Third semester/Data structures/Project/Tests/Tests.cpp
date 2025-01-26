// #include "../src/headers/Evaluator.hpp"
#include "catch_amalgamated.hpp"
#include "../src/headers/Parser.hpp"
#include "../src/headers/Lexer.hpp"
#include "../src/headers/tokenChecker.hpp"
#include "../src/headers/Evaluator.hpp"


TEST_CASE("Lexer valid single checks"){


    Lexer l;

    std::vector<std::string> inputs;
    std::vector<std::vector<Token>> tokens;

    inputs.push_back("cat");
    tokens.push_back({{Function,"cat"}});
    inputs.push_back("12");
    tokens.push_back({{Number,"12"}});
    inputs.push_back("12.5");
    tokens.push_back({{Number,"12.5"}});
    inputs.push_back("-12.5");
    tokens.push_back({{Number,"-12.5"}});
    inputs.push_back("#0");
    tokens.push_back({{Variable,"#0"}});
    inputs.push_back("(");
    tokens.push_back({{Open_bracket,"("}});
    inputs.push_back(")");
    tokens.push_back({{Close_bracket,")"}});
    

    for(int i =0;i<inputs.size();++i){
        
        l.Read(inputs[i]);

        REQUIRE(l.getTokens().size() == tokens[i].size());
        for(int j =0;j<l.getTokens().size();++j){
            REQUIRE(l.getTokens()[j].token == tokens[i][j].token);
            REQUIRE(l.getTokens()[j].val == tokens[i][j].val);
        }
        
    }

    
}

TEST_CASE("Lexer invalid numbers"){


    Lexer l;

    std::vector<std::string> inputs;

    inputs.push_back(".");
    inputs.push_back("0.");
    inputs.push_back(".0.3");
    inputs.push_back("3.0.3");

    inputs.push_back("12-32");
    inputs.push_back("-12-23");
    inputs.push_back("-12-23-");

    inputs.push_back("2qwe");

    for(int i =0;i<inputs.size();++i){        
        REQUIRE_THROWS(l.Read(inputs[i]));
    }

}
TEST_CASE("Lexer invalid words"){


    Lexer l;

    std::vector<std::string> inputs;

    inputs.push_back("asd#");
    inputs.push_back("12asd");
    inputs.push_back("asd`");
    inputs.push_back("2we");


    for(int i =0;i<inputs.size();++i){        
        REQUIRE_THROWS(l.Read(inputs[i]));
    }

}

TEST_CASE("Lexer complex checks"){


    Lexer l;

    std::vector<std::string> inputs;
    std::vector<std::vector<Token>> tokens;

    inputs.push_back("dog <- cat(#0,1,fact)");
    tokens.push_back({{Function,"dog"},{LetBe, "<-"},{Function,"cat"}, {Open_bracket, "("},{Variable,"#0"},{Comma,","},{Number,"1"},{Comma,","},{Function,"fact"},{Close_bracket,")"} });
    

    for(int i =0;i<inputs.size();++i){
        
        l.Read(inputs[i]);
        REQUIRE(l.getTokens().size() == tokens[i].size());
        for(int j =0;j<l.getTokens().size();++j){
            REQUIRE(l.getTokens()[j].token == tokens[i][j].token);
            REQUIRE(l.getTokens()[j].val == tokens[i][j].val);
        }
    }
}


TEST_CASE("tokenChecker Check some tokens"){


    Lexer l;

    tokenChecker checker;

    std::string input;

    std::vector<std::string> validInputs(0);
    std::vector<std::string> InvalidInputs(0);
    //working ones

    validInputs.push_back("dog <- cat()");
    validInputs.push_back("dog <- cat(#0,1,fact)");
    validInputs.push_back("cat(3,fact)");
    validInputs.push_back("cat()");
    for(int i = 0;i<validInputs.size();++i){
        l.Read(validInputs[i]);
        REQUIRE_NOTHROW(checker.check(l.getTokens()));
    }

    //not working standart call
    
    InvalidInputs.push_back("cat(#0)");
    InvalidInputs.push_back("cat(test,,fact)");
    InvalidInputs.push_back("cat(fact");
    InvalidInputs.push_back("cat(fact))");
    InvalidInputs.push_back("cat(fact)()");
    InvalidInputs.push_back("()");
    InvalidInputs.push_back("(");
    InvalidInputs.push_back("cat(,)");
    InvalidInputs.push_back("cat");


    //not working assoc call

    InvalidInputs.push_back("dog <- cat(#0,,fact)");
    InvalidInputs.push_back("dog <- cat(#0");
    InvalidInputs.push_back("dog <- cat(#0,fact)()");
    InvalidInputs.push_back("dog <- cat(,fact)");
    InvalidInputs.push_back("<- cat(#0,fact)");
    InvalidInputs.push_back("cat<-(#0,fact)");
    InvalidInputs.push_back("cat<-dog(#0,fact)()");
    InvalidInputs.push_back("cat<-dog(#0,fact");
    InvalidInputs.push_back("cat<-dog");


    for(int i = 0;i<InvalidInputs.size();++i){
        l.Read(InvalidInputs[i]);
        REQUIRE_THROWS(checker.check(l.getTokens()));
    }
}

TEST_CASE("Tree check"){


    Lexer lexer;

    tokenChecker checker;

    Parser parser;

    std::string input;

    //working ones

    input = ("dog <- cat()");
    lexer.Read(input);
    checker.check(lexer.getTokens());
    Associate_Exp* exp = dynamic_cast<Associate_Exp*>(parser.build(lexer.getTokens()));
    
    std::vector<Expression*> args(0);
    Associate_Exp* correct = new Associate_Exp("dog", new Function_Exp("cat",args));
    
    REQUIRE(exp != nullptr);
    REQUIRE(exp->func_name == correct->func_name);
    Function_Exp* passed_Func = dynamic_cast<Function_Exp*>(exp->expression);

    REQUIRE(passed_Func->func_name == "cat");
    REQUIRE(passed_Func->arguments.size() == 0);

    exp->Destruct();
    correct->Destruct();
    



    input = ("dog <- cat(#0,3.1,fact)");
    lexer.Read(input);
    checker.check(lexer.getTokens());
     exp = dynamic_cast<Associate_Exp*>(parser.build(lexer.getTokens()));
    
    args.clear();

    REQUIRE(exp != nullptr);
    REQUIRE(exp->func_name == "dog");
    passed_Func = dynamic_cast<Function_Exp*>(exp->expression);

    REQUIRE(passed_Func->func_name == "cat");
    REQUIRE(passed_Func->arguments.size() == 3);
    Argument_Exp* arg1 =dynamic_cast<Argument_Exp*>(passed_Func->arguments[0]);
    REQUIRE(arg1 != nullptr);
    REQUIRE(arg1->index == 0);
    Number_Exp* arg2 =dynamic_cast<Number_Exp*>(passed_Func->arguments[1]);
    REQUIRE(arg2 != nullptr);
    REQUIRE(arg2->value == 3.1);
    Function_Exp* arg3 =dynamic_cast<Function_Exp*>(passed_Func->arguments[2]);
    REQUIRE(arg3 != nullptr);
    REQUIRE(arg3->func_name == "fact");
    REQUIRE(arg3->arguments.size() == 0);

    exp->Destruct();
    {

    input = ("cat()");

    lexer.Read(input);
    checker.check(lexer.getTokens());
    Function_Exp* exp = dynamic_cast<Function_Exp*>(parser.build(lexer.getTokens()));

    REQUIRE(exp != nullptr);

    REQUIRE(exp->func_name == "cat");
    REQUIRE(exp->arguments.size() == 0);
    exp->Destruct();
    
    }
    

    input = ("cat(3,fact)");
    
    {
         lexer.Read(input);
        checker.check(lexer.getTokens());
        Function_Exp* exp = dynamic_cast<Function_Exp*>(parser.build(lexer.getTokens()));

        REQUIRE(exp != nullptr);

        REQUIRE(exp->func_name == "cat");
        REQUIRE(exp->arguments.size() == 2);

        Number_Exp* arg1 =dynamic_cast<Number_Exp*>(exp->arguments[0]);
        REQUIRE(arg1 != nullptr);
        REQUIRE(arg1->value == 3);
        Function_Exp* arg2 =dynamic_cast<Function_Exp*>(exp->arguments[1]);
        REQUIRE(arg2 != nullptr);
        REQUIRE(arg2->func_name == "fact");
        REQUIRE(arg2->arguments.size() == 0);

        exp->Destruct();
    
    }


}


TEST_CASE("Simple evaluation"){

    Lexer lexer;
    Parser parser;
    std::unordered_multimap<std::string, executeArgs> functions;
    std::vector<std::string> inputs{
        "add(1,2)",
        "sub(5,2)",
        "mul(3,2)",
        "div(4,2)",
        "div(5,2)",
        "pow(5,2)",
        "sqrt(25)",
        "sin(30)",
        "cos(30)",
        "eq(1 0)",
        "eq(2 2)",
        "le(1 2)",
        "le(2 2)",
        "le(2 1)",
        "nand(1 1)",
        "nand(1 0)",
        "if(1 2 3)",
        "if(0 2 3)"
    };
    std::vector<double> correct{
        3,3,6,2,2.5,25,5,-0.98803162409286183,0.15425144988758405,0,1,
        1,1,0,0,1,2,3
    };

    for(int i =0;i<inputs.size();++i){
        lexer.Read(inputs[i]);
        Expression * exp =parser.build(lexer.getTokens());
        enviroment emptyEnv;
        Evaluator eval(exp,functions,emptyEnv);
        Number_Exp* res = dynamic_cast<Number_Exp*>(eval.evaluate());
        REQUIRE(res->value == correct[i]);
        res->Destruct();
        exp->Destruct();
    }
    

}

TEST_CASE("List evaluation"){

    Lexer lexer;
    Parser parser;
    std::unordered_multimap<std::string, executeArgs> functions;
    std::vector<std::string> inputs{
        "list()",
        "list(1)",
        "list(1,2)",
        "list(add(1,2),mul(2,2))"
    };
    {
        lexer.Read(inputs[0]);
        Expression * exp =parser.build(lexer.getTokens());
        enviroment emptyEnv;
        Evaluator eval(exp,functions,emptyEnv);
        List_Exp* res = dynamic_cast<List_Exp*>(eval.evaluate());
        
        REQUIRE(res != nullptr);
        REQUIRE(res->value == nullptr);
        REQUIRE(res->next == nullptr);
        // Number_Exp* num;
        // num = dynamic_cast<Number_Exp*>(res->value); 
        res->Destruct();
        exp->Destruct();

    }
    {
        lexer.Read(inputs[1]);
        Expression * exp =parser.build(lexer.getTokens());
        enviroment emptyEnv;
        Evaluator eval(exp,functions,emptyEnv);
        List_Exp* res = dynamic_cast<List_Exp*>(eval.evaluate());
        
        REQUIRE(res != nullptr);
        REQUIRE(res->value != nullptr);
        REQUIRE(res->next != nullptr);
        REQUIRE(res->next->value == nullptr);
        REQUIRE(res->next->next == nullptr);
        Number_Exp* num;
        num = dynamic_cast<Number_Exp*>(res->value);
        REQUIRE(num); 
        REQUIRE(num->value == 1); 
        res->Destruct();
        exp->Destruct();

    }
    {
        lexer.Read(inputs[2]);
        Expression * exp =parser.build(lexer.getTokens());
        enviroment emptyEnv;
        Evaluator eval(exp,functions,emptyEnv);
        List_Exp* res = dynamic_cast<List_Exp*>(eval.evaluate());
        
        REQUIRE(res != nullptr);
        REQUIRE(res->value != nullptr);
        REQUIRE(res->next != nullptr);
        REQUIRE(res->next->value != nullptr);
        REQUIRE(res->next->next != nullptr);
        REQUIRE(res->next->next->value == nullptr);
        REQUIRE(res->next->next->next == nullptr);
        Number_Exp* num;
        num = dynamic_cast<Number_Exp*>(res->value);
        REQUIRE(num); 
        REQUIRE(num->value == 1); 
        num = dynamic_cast<Number_Exp*>(res->next->value);
        REQUIRE(num); 
        REQUIRE(num->value == 2); 
        res->Destruct();
        exp->Destruct();

    }
    {
        lexer.Read(inputs[3]);
        Expression * exp =parser.build(lexer.getTokens());
        enviroment emptyEnv;
        Evaluator eval(exp,functions,emptyEnv);
        List_Exp* res = dynamic_cast<List_Exp*>(eval.evaluate());
        
        REQUIRE(res != nullptr);
        REQUIRE(res->value != nullptr);
        REQUIRE(res->next != nullptr);
        REQUIRE(res->next->value != nullptr);
        REQUIRE(res->next->next != nullptr);
        REQUIRE(res->next->next->value == nullptr);
        REQUIRE(res->next->next->next == nullptr);
        Number_Exp* num;
        num = dynamic_cast<Number_Exp*>(res->value);
        REQUIRE(num); 
        REQUIRE(num->value == 3); 
        num = dynamic_cast<Number_Exp*>(res->next->value);
        REQUIRE(num); 
        REQUIRE(num->value == 4); 
        res->Destruct();
        exp->Destruct();

    }
}

TEST_CASE("Association test"){

    Lexer lexer;
    Parser parser;
    std::unordered_multimap<std::string, executeArgs> functions;
    std::vector<std::string> inputs{
        "add1 <- add(#0,1)",
        "comp <- add(1,2)"
    };
    {
        lexer.Read(inputs[0]);
        Expression * exp =parser.build(lexer.getTokens());
        enviroment emptyEnv;
        Evaluator eval(exp,functions,emptyEnv);
        Associate_Exp* res = dynamic_cast<Associate_Exp*>(eval.evaluate());
        REQUIRE(res);
        REQUIRE(res->func_name == "add1");
        Function_Exp* func = dynamic_cast<Function_Exp*>(res->expression);
        REQUIRE(func->func_name == "add");
        REQUIRE(func->arguments.size() == 2);
        Argument_Exp* arg1 = dynamic_cast<Argument_Exp*>(func->arguments[0]);
        REQUIRE(arg1);
        REQUIRE(arg1->index == 0);
        
        Number_Exp* arg2 = dynamic_cast<Number_Exp*>(func->arguments[1]);
        REQUIRE(arg2);
        REQUIRE(arg2->value == 1);
        delete exp;
    }

    {
        lexer.Read(inputs[1]);
        Expression * exp =parser.build(lexer.getTokens());
        enviroment emptyEnv;
        Evaluator eval(exp,functions,emptyEnv);
        Associate_Exp* res = dynamic_cast<Associate_Exp*>(eval.evaluate());
        REQUIRE(res);
        REQUIRE(res->func_name == "comp");
        REQUIRE(!res->expression);
        delete exp;

    }

    REQUIRE(functions.size() == 2);
    {
    REQUIRE(functions.find("add1")->second.argc == 1);
    Expression* exp = functions.find("add1")->second.function;
    Function_Exp* func = dynamic_cast<Function_Exp*>(exp);
    REQUIRE(func);
    REQUIRE(func->func_name == "add");
    REQUIRE(dynamic_cast<Argument_Exp*>(func->arguments[0]));
    REQUIRE(dynamic_cast<Argument_Exp*>(func->arguments[0])->index == 0);
    REQUIRE(dynamic_cast<Number_Exp*>(func->arguments[1]));
    REQUIRE(dynamic_cast<Number_Exp*>(func->arguments[1])->value == 1);

    }

    {
    REQUIRE(functions.find("comp")->second.argc == 0);
    Expression* exp = functions.find("comp")->second.function;
    Number_Exp* num = dynamic_cast<Number_Exp*>(exp);
    REQUIRE(num);
    REQUIRE(num->value == 3);
    }

    for(auto it = functions.begin(); it != functions.end();){
        it->second.function->Destruct();
        it++;
    }
}

TEST_CASE("Function overloading"){
     Lexer lexer;
    Parser parser;
    std::unordered_multimap<std::string, executeArgs> functions;
    std::vector<std::string> inputs{
        "comp <- add(#0,1)",
        "comp <- add(#0,#1)"
    };
    {
        lexer.Read(inputs[0]);
        Expression * exp =parser.build(lexer.getTokens());
        enviroment emptyEnv;
        Evaluator eval(exp,functions,emptyEnv);
        Associate_Exp* res = dynamic_cast<Associate_Exp*>(eval.evaluate());
        REQUIRE(res);
        REQUIRE(res->func_name == "comp");
        Function_Exp* func = dynamic_cast<Function_Exp*>(res->expression);
        REQUIRE(func->func_name == "add");
        REQUIRE(func->arguments.size() == 2);
        Argument_Exp* arg1 = dynamic_cast<Argument_Exp*>(func->arguments[0]);
        REQUIRE(arg1);
        REQUIRE(arg1->index == 0);
        
        Number_Exp* arg2 = dynamic_cast<Number_Exp*>(func->arguments[1]);
        REQUIRE(arg2);
        REQUIRE(arg2->value == 1);
        delete exp;
    }
    {
        lexer.Read(inputs[1]);
        Expression * exp =parser.build(lexer.getTokens());
        enviroment emptyEnv;
        Evaluator eval(exp,functions,emptyEnv);
        Associate_Exp* res = dynamic_cast<Associate_Exp*>(eval.evaluate());
        REQUIRE(res);
        REQUIRE(res->func_name == "comp");
        Function_Exp* func = dynamic_cast<Function_Exp*>(res->expression);
        REQUIRE(func->func_name == "add");
        REQUIRE(func->arguments.size() == 2);
        Argument_Exp* arg1 = dynamic_cast<Argument_Exp*>(func->arguments[0]);
        REQUIRE(arg1);
        REQUIRE(arg1->index == 0);
        Argument_Exp* arg2 = dynamic_cast<Argument_Exp*>(func->arguments[1]);
        REQUIRE(arg2);
        REQUIRE(arg2->index == 1);
        delete exp;
    }

    REQUIRE(functions.size() == 2);

    auto [begin,end] = functions.equal_range("comp");

    REQUIRE(begin != nullptr);
    {
    REQUIRE(begin->second.argc == 1);
    Function_Exp* func = dynamic_cast<Function_Exp*>(begin->second.function);
    REQUIRE(func->func_name == "add");
    REQUIRE(func->arguments.size() == 2);
    Argument_Exp* arg1 = dynamic_cast<Argument_Exp*>(func->arguments[0]);
    REQUIRE(arg1);
    REQUIRE(arg1->index == 0);
        
    Number_Exp* arg2 = dynamic_cast<Number_Exp*>(func->arguments[1]);
    REQUIRE(arg2);
    REQUIRE(arg2->value == 1);
    }
     
     begin++;
    REQUIRE(begin != nullptr);
    {
    REQUIRE(begin->second.argc == 2);
    Function_Exp* func = dynamic_cast<Function_Exp*>(begin->second.function);
    REQUIRE(func->func_name == "add");
    REQUIRE(func->arguments.size() == 2);
    Argument_Exp* arg1 = dynamic_cast<Argument_Exp*>(func->arguments[0]);
    REQUIRE(arg1);
    REQUIRE(arg1->index == 0);
        
    Argument_Exp* arg2 = dynamic_cast<Argument_Exp*>(func->arguments[1]);
    REQUIRE(arg2);
    REQUIRE(arg2->index == 1);
    }
    for(auto it = functions.begin(); it != functions.end();){
        it->second.function->Destruct();
        it++;
    }
}
TEST_CASE("Invalid functions throw"){
    Lexer lexer;
    Parser parser;
    std::unordered_multimap<std::string, executeArgs> functions;
    std::vector<std::string> inputs{
        "comp <- fish(#0)",
        "comp <- fish()",
    
        "comp(1)"
    };
    {
    lexer.Read(inputs[0]);
    Expression* exp = parser.build(lexer.getTokens());
    enviroment env;
    Evaluator eval(exp,functions,env);
    exp = eval.evaluate();
    delete exp;
    }
    {
    lexer.Read(inputs[1]);
    Expression* exp = parser.build(lexer.getTokens());
    enviroment env;
    Evaluator eval(exp,functions,env);
    REQUIRE_THROWS(eval.evaluate());
    exp->Destruct();
    }
    {
    lexer.Read(inputs[2]);
    Expression* exp = parser.build(lexer.getTokens());
    enviroment env;
    Evaluator eval(exp,functions,env);
    REQUIRE_THROWS(eval.evaluate());
    exp->Destruct();
    }
    for(auto it = functions.begin(); it != functions.end();){
        it->second.function->Destruct();
        it++;
    }

}

///////////////////////////////////////////

TEST_CASE("List functions"){
    Lexer lexer;
    Parser parser;
    std::unordered_multimap<std::string, executeArgs> functions;
    std::vector<std::string> inputs{
        "double <- mul(#0,2)",
        "map(double, list(1,2,3))",
        "lessOrEqualTo2 <- le(#0,2)",
        "filter(lessOrEqualTo2,list(1,2,3,4))"
    };
    {
    lexer.Read(inputs[0]);
    Expression* exp = parser.build(lexer.getTokens());
    enviroment env;
    Evaluator eval(exp,functions,env);
    exp = eval.evaluate();
    delete exp;
    } 
    {
    lexer.Read(inputs[1]);
    Expression* exp = parser.build(lexer.getTokens());
    enviroment env;
    Evaluator eval(exp,functions,env);
    List_Exp* list = dynamic_cast<List_Exp*>(eval.evaluate());
    {
        Number_Exp* num = dynamic_cast<Number_Exp*>(list->value);
        REQUIRE(num);
        REQUIRE(num->value == 2);
    }
    {
        Number_Exp* num = dynamic_cast<Number_Exp*>(list->next->value);
        REQUIRE(num);
        REQUIRE(num->value == 4);
    }
    {
        Number_Exp* num = dynamic_cast<Number_Exp*>(list->next->next->value);
        REQUIRE(num);
        REQUIRE(num->value == 6);
    }
    {
        Number_Exp* num = dynamic_cast<Number_Exp*>(list->next->next->next->value);
        REQUIRE(num == nullptr);
        REQUIRE(list->next->next->next->value == nullptr);
    }
    REQUIRE(list->next->next->next->next == nullptr);

    list->Destruct();
    delete exp;
    }
    {
    lexer.Read(inputs[2]);
    Expression* exp = parser.build(lexer.getTokens());
    enviroment env;
    Evaluator eval(exp,functions,env);
    exp = eval.evaluate();
    delete exp;
    } 
    {
    lexer.Read(inputs[3]);
    Expression* exp = parser.build(lexer.getTokens());
    enviroment env;
    Evaluator eval(exp,functions,env);
    List_Exp* list = dynamic_cast<List_Exp*>(eval.evaluate());
    {
        Number_Exp* num = dynamic_cast<Number_Exp*>(list->value);
        REQUIRE(num);
        REQUIRE(num->value == 1);
    }
    {
        Number_Exp* num = dynamic_cast<Number_Exp*>(list->next->value);
        REQUIRE(num);
        REQUIRE(num->value == 2);
    }
    {
        Number_Exp* num = dynamic_cast<Number_Exp*>(list->next->next->value);
        REQUIRE(num == nullptr);
        REQUIRE(list->next->next->value == nullptr);
    }
    REQUIRE(list->next->next->next == nullptr);
 
    list->Destruct();
    delete exp;
    }
      for(auto it = functions.begin(); it != functions.end();){
        it->second.function->Destruct();
        it++;
    }

}
TEST_CASE("Not complete function detection in list functions call"){
    
     Lexer lexer;
    Parser parser;
    std::unordered_multimap<std::string, executeArgs> functions;
    std::vector<std::string> inputs{
        "double <- cat(#0,2)",
        "map(double, list(1,2,3))",
        "lessOrEqualTo2 <- fish(#0,2)",
        "filter(lessOrEqualTo2,list(1,2,3,4))"
    };

   
    {
    lexer.Read(inputs[0]);
    Expression* exp = parser.build(lexer.getTokens());
    enviroment env;
    Evaluator eval(exp,functions,env);
    exp = eval.evaluate();
    delete exp;
    } 
    {
    lexer.Read(inputs[1]);
    Expression* exp = parser.build(lexer.getTokens());
    enviroment env;
    Evaluator eval(exp,functions,env);
    REQUIRE_THROWS(eval.evaluate());  
    delete exp;
    }
    {
    lexer.Read(inputs[2]);
    Expression* exp = parser.build(lexer.getTokens());
    enviroment env;
    Evaluator eval(exp,functions,env);
    exp = eval.evaluate();
    delete exp;
    } 
    {
    lexer.Read(inputs[3]);
    Expression* exp = parser.build(lexer.getTokens());
    enviroment env;
    Evaluator eval(exp,functions,env);
    REQUIRE_THROWS(eval.evaluate());  
    }
    for(auto it = functions.begin(); it != functions.end();){
        it->second.function->Destruct();
        it++;
    }
}
TEST_CASE("Example given"){
    
    
    Lexer lexer;
    Parser parser;
    std::unordered_multimap<std::string, executeArgs> functions;

    std::vector<std::string> assoc{
"myConst <- 7",
"doubleArg <- add(#0, #0)",
"sumSqr <- add(mul(#0, #0), mul(#1, #1))",
"myList <- list(1, 2, 3, 4)",
"double <- mul(#0, #0)",
"biggerThanTwo <- nand(le(#0, 2), 1)",
"fact <- if(eq(#0, 0), 1, mul(#0, fact(sub(#0, 1))))"   
    };

    std::vector<std::string> inputs{
        "add(3, 7)",
        "add(add(3, 5), add(10, 10))",
        "myConst()",
        "doubleArg(5)",
        "sumSqr(5, 10)",
        "if(1, 7, 11)",
        "if(0, 7, 11)",
        "if(add(5, -5), 3, 5)",
        "fact(0)",
        "fact(5)"
    };
   for(int i =0;i<assoc.size();++i){
        lexer.Read(assoc[i]);
        Expression * exp =parser.build(lexer.getTokens());
        enviroment emptyEnv;
        Evaluator eval(exp,functions,emptyEnv);
        REQUIRE_NOTHROW(eval.evaluate());
        delete exp;
    }
   
    std::vector<double> correct{
        10,28,7,10,125,7,11,5,1,120
    };

    for(int i =0;i<inputs.size();++i){
        lexer.Read(inputs[i]);
        Expression * exp =parser.build(lexer.getTokens());
        enviroment emptyEnv;
        Evaluator eval(exp,functions,emptyEnv);
        Number_Exp* res = dynamic_cast<Number_Exp*>(eval.evaluate());
        REQUIRE(res->value == correct[i]);
        if(eval.isNewlyCreated()){
            res->Destruct();
        }
        exp->Destruct();
    }


    {
        lexer.Read("map(double, myList())");
        Expression * exp =parser.build(lexer.getTokens());
        enviroment emptyEnv;
        Evaluator eval(exp,functions,emptyEnv);
        Expression* temp = eval.evaluate();
        List_Exp* res = dynamic_cast<List_Exp*>(temp);

        {
        Number_Exp* num = dynamic_cast<Number_Exp*>(res->value);
        REQUIRE(num);
        REQUIRE(num->value == 1);
        }
        {
        Number_Exp* num = dynamic_cast<Number_Exp*>(res->next->value);
        REQUIRE(num);
        REQUIRE(num->value == 4);
        }
        {
        Number_Exp* num = dynamic_cast<Number_Exp*>(res->next->next->value);
        REQUIRE(num);
        REQUIRE(num->value == 9);
        }
        {
        Number_Exp* num = dynamic_cast<Number_Exp*>(res->next->next->next->value);
        REQUIRE(num);
        REQUIRE(num->value == 16);
        }
        {
        Number_Exp* num = dynamic_cast<Number_Exp*>(res->next->next->next->next->value);
        REQUIRE(num == nullptr);
        REQUIRE(res->next->next->next->next->value == nullptr);
        }
        
        
        res->Destruct();
        exp->Destruct();
    }
    for(auto it = functions.begin(); it != functions.end();){
        it->second.function->Destruct();
        it++;
    }
}