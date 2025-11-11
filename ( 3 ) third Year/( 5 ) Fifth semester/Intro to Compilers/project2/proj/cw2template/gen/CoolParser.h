
// Generated from /home/student/my-code/cw2template/tools/../src/CoolParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  CoolParser : public antlr4::Parser {
public:
  enum {
    SEMI = 1, OCURLY = 2, CCURLY = 3, OPAREN = 4, COMMA = 5, CPAREN = 6, 
    COLON = 7, AT = 8, DOT = 9, PLUS = 10, MINUS = 11, STAR = 12, SLASH = 13, 
    TILDE = 14, LT = 15, EQ = 16, DARROW = 17, ASSIGN = 18, LE = 19, CLASS = 20, 
    ELSE = 21, FI = 22, IF = 23, IN = 24, INHERITS = 25, ISVOID = 26, LET = 27, 
    LOOP = 28, POOL = 29, THEN = 30, WHILE = 31, CASE = 32, ESAC = 33, NEW = 34, 
    OF = 35, NOT = 36, BOOL_CONST = 37, INT_CONST = 38, OBJECTID = 39, TYPEID = 40, 
    WS = 41, STR_BEGIN = 42, COMM_BEGIN = 43, COMM_ERR1 = 44, LCOMM_BEGIN = 45, 
    ERROR = 46, STR_CONST = 47, STR_END = 48, STR_ESC_NL = 49, ESC_BS = 50, 
    ESC_FF = 51, ESC_TAB = 52, ESC_NULL = 53, ESC_ANY = 54, NULL_ = 55, 
    STR_NL = 56, STR_ERR = 57, STR_ANY = 58, ESTR_END = 59, ESTR_ESC_NL = 60, 
    ESTR_NL = 61, ESTR_ANY = 62, OCOMM = 63, CCOMM = 64, COMM_SKIP = 65, 
    COMM_ERR = 66, LCOMM_END = 67, LCOMM_SKIP = 68
  };

  enum {
    RuleProgram = 0, RuleClass = 1
  };

  explicit CoolParser(antlr4::TokenStream *input);

  CoolParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~CoolParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProgramContext;
  class ClassContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ClassContext *> class_();
    ClassContext* class_(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMI();
    antlr4::tree::TerminalNode* SEMI(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  ClassContext : public antlr4::ParserRuleContext {
  public:
    ClassContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CLASS();
    antlr4::tree::TerminalNode *TYPEID();
    antlr4::tree::TerminalNode *OCURLY();
    antlr4::tree::TerminalNode *CCURLY();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassContext* class_();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

