
// Generated from /home/student/my-code/cw1/tools/../src/CoolLexer.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  CoolLexer : public antlr4::Lexer {
public:
  enum {
    STR_CONST = 1, ERROR = 2, SEMI = 3, DARROW = 4, PLUS = 5, MINUS = 6, 
    DIV = 7, MUL = 8, LESS = 9, L_EQ = 10, EQ = 11, DOT = 12, OPEN_CURLY = 13, 
    CLOSE_CURLY = 14, OPEN_BRAC = 15, CLOSE_BRAC = 16, COMMA = 17, DOUBLE_POINTS = 18, 
    AT = 19, WIGGLE = 20, WS = 21, BOOL_CONST = 22, LINE_COMMENT = 23, UNMATCHED_COMMENT_END = 24, 
    COMMENT = 25, ASSIGN = 26, CASE = 27, CLASS = 28, ELSE = 29, ESAC = 30, 
    FI = 31, IF = 32, IN = 33, INHERITS = 34, ISVOID = 35, LE = 36, LET = 37, 
    LOOP = 38, NEW = 39, NOT = 40, OF = 41, POOL = 42, THEN = 43, WHILE = 44, 
    INT_CONST = 45, OBJECTID = 46, TYPEID = 47, INVALID_SYMBOL = 48, INVALID_UNDERSCORE = 49, 
    STRING_START = 50, ERROR_UNMATCHED_OPEN_COMMENT = 51, STRING_NEW_LINE_SLASH = 52, 
    STRING_TAB = 53, STRING_FORMFEED = 54, STRING_BACKSPACE = 55, STRING_ESCAPE = 56, 
    STRING_ESC_SEQ = 57, STRING_ESC_SEQ_NULL = 58, STRING_CARRIAGE_RETURN = 59, 
    STRING_SLASH_SYMBOL = 60, STRING_NORMAL_CHARS = 61, STRING_NEW_LINE_UNESCPAED = 62, 
    STRING_END = 63, NESTED_COMMENT_START = 64, NESTED_COMMENT_END = 65, 
    COMMENT_CONTENT = 66, UNCLOSED_COMMENT_AT_EOF = 67
  };

  enum {
    STRING_MODE = 1, COMMENT_MODE = 2
  };

  explicit CoolLexer(antlr4::CharStream *input);

  ~CoolLexer() override;


      const unsigned MAX_STR_CONST = 1024;
      std::vector<char> string_buffer;

      bool null_Symbol_ESCAPE =false;
      int charCount = 0;
      bool null_Symbol = false;
      std::map<int, bool> bool_values;

      void assoc_bool_with_token(bool value) {
          bool_values[tokenStartCharIndex] = value;
      }

      bool get_bool_value(int token_start_char_index) {
          return bool_values.at(token_start_char_index);
      }

       int isInStringMode() const {
          return charCount;
      }

      bool escaped = false;




  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  void action(antlr4::RuleContext *context, size_t ruleIndex, size_t actionIndex) override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.
  void BOOL_CONSTAction(antlr4::RuleContext *context, size_t actionIndex);
  void UNMATCHED_COMMENT_ENDAction(antlr4::RuleContext *context, size_t actionIndex);
  void INVALID_UNDERSCOREAction(antlr4::RuleContext *context, size_t actionIndex);
  void STRING_STARTAction(antlr4::RuleContext *context, size_t actionIndex);
  void STRING_NEW_LINE_SLASHAction(antlr4::RuleContext *context, size_t actionIndex);
  void STRING_TABAction(antlr4::RuleContext *context, size_t actionIndex);
  void STRING_FORMFEEDAction(antlr4::RuleContext *context, size_t actionIndex);
  void STRING_BACKSPACEAction(antlr4::RuleContext *context, size_t actionIndex);
  void STRING_ESCAPEAction(antlr4::RuleContext *context, size_t actionIndex);
  void STRING_ESC_SEQAction(antlr4::RuleContext *context, size_t actionIndex);
  void STRING_ESC_SEQ_NULLAction(antlr4::RuleContext *context, size_t actionIndex);
  void STRING_CARRIAGE_RETURNAction(antlr4::RuleContext *context, size_t actionIndex);
  void STRING_SLASH_SYMBOLAction(antlr4::RuleContext *context, size_t actionIndex);
  void STRING_NORMAL_CHARSAction(antlr4::RuleContext *context, size_t actionIndex);
  void STRING_NEW_LINE_UNESCPAEDAction(antlr4::RuleContext *context, size_t actionIndex);
  void STRING_ENDAction(antlr4::RuleContext *context, size_t actionIndex);
  void UNCLOSED_COMMENT_AT_EOFAction(antlr4::RuleContext *context, size_t actionIndex);

  // Individual semantic predicate functions triggered by sempred() above.

};

