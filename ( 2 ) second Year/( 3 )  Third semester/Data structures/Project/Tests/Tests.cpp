// #include "../src/headers/Evaluator.hpp"
#include "catch_amalgamated.hpp"
#include "../src/headers/Parser.hpp"
#include "../src/headers/Lexer.hpp"
#include "../src/headers/tokenChecker.hpp"


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

    //working ones
    input = ("dog <- cat(#0,1,fact)");
    l.Read(input);
    REQUIRE_NOTHROW(checker.check(l.getTokens()));
      input = ("dog <- cat()");
    l.Read(input);
    REQUIRE_NOTHROW(checker.check(l.getTokens()));

    input = ("cat(3,fact)");
    l.Read(input);
    REQUIRE_NOTHROW(checker.check(l.getTokens()));
    input = ("cat()");
    l.Read(input);
    REQUIRE_NOTHROW(checker.check(l.getTokens()));

    //not working standart call
    input = ("cat(#0)");
    l.Read(input);
    REQUIRE_THROWS(checker.check(l.getTokens()));
    input = ("cat(test,,fact)");
    l.Read(input);
    REQUIRE_THROWS(checker.check(l.getTokens()));
    input = ("cat(fact");
    l.Read(input);
    REQUIRE_THROWS(checker.check(l.getTokens()));
    input = ("cat(fact))");
    l.Read(input);
    REQUIRE_THROWS(checker.check(l.getTokens()));
    input = ("cat(fact)()");
    l.Read(input);
    REQUIRE_THROWS(checker.check(l.getTokens()));
    input = ("()");
    l.Read(input);
    REQUIRE_THROWS(checker.check(l.getTokens()));
    input = ("(");
    l.Read(input);
    REQUIRE_THROWS(checker.check(l.getTokens()));
    input = ("cat(,)");
    l.Read(input);
    REQUIRE_THROWS(checker.check(l.getTokens()));
    input = ("cat");
    l.Read(input);
    REQUIRE_THROWS(checker.check(l.getTokens()));


    //not working assoc call

    input = ("dog <- cat(#0,,fact)");
    l.Read(input);
    REQUIRE_THROWS(checker.check(l.getTokens()));

    input = ("dog <- cat(#0");
    l.Read(input);
    REQUIRE_THROWS(checker.check(l.getTokens()));

    input = ("dog <- cat(#0,fact)()");
    l.Read(input);
    REQUIRE_THROWS(checker.check(l.getTokens()));
        
    input = ("dog <- cat(,fact)");
    l.Read(input);
    REQUIRE_THROWS(checker.check(l.getTokens()));


    input = ("<- cat(#0,fact)");
    l.Read(input);
    REQUIRE_THROWS(checker.check(l.getTokens()));
    input = ("cat<-(#0,fact)");
    l.Read(input);
    REQUIRE_THROWS(checker.check(l.getTokens()));
    input = ("cat<-dog(#0,fact)()");
    l.Read(input);
    REQUIRE_THROWS(checker.check(l.getTokens()));
    input = ("cat<-dog(#0,fact");
    l.Read(input);
    REQUIRE_THROWS(checker.check(l.getTokens()));
    input = ("cat<-dog");
    l.Read(input);
    REQUIRE_THROWS(checker.check(l.getTokens()));
}
