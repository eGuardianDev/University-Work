
// Generated from /home/student/my-code/cw1/tools/../src/CoolLexer.g4 by ANTLR 4.13.2


#include "CoolLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct CoolLexerStaticData final {
  CoolLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CoolLexerStaticData(const CoolLexerStaticData&) = delete;
  CoolLexerStaticData(CoolLexerStaticData&&) = delete;
  CoolLexerStaticData& operator=(const CoolLexerStaticData&) = delete;
  CoolLexerStaticData& operator=(CoolLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag coollexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<CoolLexerStaticData> coollexerLexerStaticData = nullptr;

void coollexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (coollexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(coollexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<CoolLexerStaticData>(
    std::vector<std::string>{
      "SEMI", "DARROW", "PLUS", "MINUS", "DIV", "MUL", "LESS", "L_EQ", "EQ", 
      "DOT", "OPEN_CURLY", "CLOSE_CURLY", "OPEN_BRAC", "CLOSE_BRAC", "COMMA", 
      "DOUBLE_POINTS", "AT", "WIGGLE", "WS", "BOOL_CONST", "LINE_COMMENT", 
      "UNMATCHED_COMMENT_END", "COMMENT", "ASSIGN", "CASE", "CLASS", "ELSE", 
      "ESAC", "FI", "IF", "IN", "INHERITS", "ISVOID", "LE", "LET", "LOOP", 
      "NEW", "NOT", "OF", "POOL", "THEN", "WHILE", "INT_CONST", "OBJECTID", 
      "TYPEID", "INVALID_SYMBOL", "INVALID_UNDERSCORE", "STRING_START", 
      "ERROR_UNMATCHED_OPEN_COMMENT", "STRING_NEW_LINE_SLASH", "STRING_TAB", 
      "STRING_FORMFEED", "STRING_BACKSPACE", "STRING_ESCAPE", "STRING_ESC_SEQ", 
      "STRING_ESC_SEQ_NULL", "STRING_CARRIAGE_RETURN", "STRING_SLASH_SYMBOL", 
      "STRING_NORMAL_CHARS", "STRING_NEW_LINE_UNESCPAED", "STRING_END", 
      "NESTED_COMMENT_START", "NESTED_COMMENT_END", "COMMENT_CONTENT", "UNCLOSED_COMMENT_AT_EOF"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE", "STRING_MODE", "COMMENT_MODE"
    },
    std::vector<std::string>{
      "", "", "", "';'", "'=>'", "'+'", "'-'", "'/'", "'*'", "'<'", "'<='", 
      "'='", "'.'", "'{'", "'}'", "'('", "')'", "','", "':'", "'@'", "'~'", 
      "", "", "", "", "", "'<-'"
    },
    std::vector<std::string>{
      "", "STR_CONST", "ERROR", "SEMI", "DARROW", "PLUS", "MINUS", "DIV", 
      "MUL", "LESS", "L_EQ", "EQ", "DOT", "OPEN_CURLY", "CLOSE_CURLY", "OPEN_BRAC", 
      "CLOSE_BRAC", "COMMA", "DOUBLE_POINTS", "AT", "WIGGLE", "WS", "BOOL_CONST", 
      "LINE_COMMENT", "UNMATCHED_COMMENT_END", "COMMENT", "ASSIGN", "CASE", 
      "CLASS", "ELSE", "ESAC", "FI", "IF", "IN", "INHERITS", "ISVOID", "LE", 
      "LET", "LOOP", "NEW", "NOT", "OF", "POOL", "THEN", "WHILE", "INT_CONST", 
      "OBJECTID", "TYPEID", "INVALID_SYMBOL", "INVALID_UNDERSCORE", "STRING_START", 
      "ERROR_UNMATCHED_OPEN_COMMENT", "STRING_NEW_LINE_SLASH", "STRING_TAB", 
      "STRING_FORMFEED", "STRING_BACKSPACE", "STRING_ESCAPE", "STRING_ESC_SEQ", 
      "STRING_ESC_SEQ_NULL", "STRING_CARRIAGE_RETURN", "STRING_SLASH_SYMBOL", 
      "STRING_NORMAL_CHARS", "STRING_NEW_LINE_UNESCPAED", "STRING_END", 
      "NESTED_COMMENT_START", "NESTED_COMMENT_END", "COMMENT_CONTENT", "UNCLOSED_COMMENT_AT_EOF"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,67,503,6,-1,6,-1,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,
  	7,5,2,6,7,6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,
  	7,13,2,14,7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,
  	7,20,2,21,7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,
  	7,27,2,28,7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,
  	7,34,2,35,7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,
  	7,41,2,42,7,42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,
  	7,48,2,49,7,49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,
  	7,55,2,56,7,56,2,57,7,57,2,58,7,58,2,59,7,59,2,60,7,60,2,61,7,61,2,62,
  	7,62,2,63,7,63,2,64,7,64,1,0,1,0,1,1,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,
  	1,5,1,5,1,6,1,6,1,7,1,7,1,7,1,8,1,8,1,9,1,9,1,10,1,10,1,11,1,11,1,12,
  	1,12,1,13,1,13,1,14,1,14,1,15,1,15,1,16,1,16,1,17,1,17,1,18,4,18,173,
  	8,18,11,18,12,18,174,1,18,1,18,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,
  	1,19,1,19,1,19,3,19,190,8,19,1,20,1,20,1,20,1,20,5,20,196,8,20,10,20,
  	12,20,199,9,20,1,20,1,20,1,21,1,21,1,21,1,21,1,21,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,23,1,23,1,23,1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,3,24,
  	225,8,24,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,3,25,237,8,
  	25,1,26,1,26,1,26,1,26,1,26,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,3,
  	27,252,8,27,1,28,1,28,1,28,1,28,3,28,258,8,28,1,29,1,29,1,29,1,30,1,30,
  	1,30,1,30,3,30,267,8,30,1,31,1,31,1,31,1,31,1,31,1,31,1,31,1,31,1,31,
  	1,31,1,31,1,31,1,31,1,31,1,31,1,31,3,31,285,8,31,1,32,1,32,1,32,1,32,
  	1,32,1,32,1,32,1,32,1,32,1,32,1,32,1,32,3,32,299,8,32,1,33,1,33,1,33,
  	1,33,3,33,305,8,33,1,34,1,34,1,34,1,34,1,34,1,34,3,34,313,8,34,1,35,1,
  	35,1,35,1,35,1,35,1,35,1,35,1,35,3,35,323,8,35,1,36,1,36,1,36,1,36,1,
  	36,1,36,3,36,331,8,36,1,37,1,37,1,37,1,37,1,37,1,37,3,37,339,8,37,1,38,
  	1,38,1,38,1,38,3,38,345,8,38,1,39,1,39,1,39,1,39,1,39,1,39,1,39,1,39,
  	3,39,355,8,39,1,40,1,40,1,40,1,40,1,40,1,40,1,40,1,40,3,40,365,8,40,1,
  	41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,1,41,3,41,377,8,41,1,42,4,
  	42,380,8,42,11,42,12,42,381,1,43,1,43,5,43,386,8,43,10,43,12,43,389,9,
  	43,1,44,1,44,5,44,393,8,44,10,44,12,44,396,9,44,1,45,1,45,1,46,1,46,1,
  	46,1,46,1,46,1,47,1,47,1,47,1,47,1,47,1,47,1,48,1,48,1,49,1,49,1,49,1,
  	49,1,49,1,49,1,50,1,50,1,50,1,50,1,50,1,50,1,51,1,51,1,51,1,51,1,51,1,
  	51,1,52,1,52,1,52,1,52,1,52,1,52,1,53,1,53,1,53,1,53,1,53,1,54,1,54,1,
  	54,1,54,1,54,1,54,1,55,1,55,1,55,1,55,1,55,1,55,1,56,1,56,1,56,1,56,1,
  	56,1,57,1,57,1,57,1,57,1,57,1,57,1,58,4,58,466,8,58,11,58,12,58,467,1,
  	58,1,58,1,58,1,58,1,59,1,59,1,59,1,59,1,59,1,60,1,60,1,60,1,60,1,60,1,
  	61,1,61,1,61,1,61,1,61,1,61,1,62,1,62,1,62,1,62,1,62,1,62,1,63,1,63,1,
  	63,1,63,1,64,1,64,1,64,1,64,0,0,65,3,3,5,4,7,5,9,6,11,7,13,8,15,9,17,
  	10,19,11,21,12,23,13,25,14,27,15,29,16,31,17,33,18,35,19,37,20,39,21,
  	41,22,43,23,45,24,47,25,49,26,51,27,53,28,55,29,57,30,59,31,61,32,63,
  	33,65,34,67,35,69,36,71,37,73,38,75,39,77,40,79,41,81,42,83,43,85,44,
  	87,45,89,46,91,47,93,48,95,49,97,50,99,51,101,52,103,53,105,54,107,55,
  	109,56,111,57,113,58,115,59,117,60,119,61,121,62,123,63,125,64,127,65,
  	129,66,131,67,3,0,1,2,18,2,0,9,13,32,32,2,0,82,82,114,114,2,0,85,85,117,
  	117,2,0,69,69,101,101,2,0,65,65,97,97,2,0,76,76,108,108,2,0,83,83,115,
  	115,2,0,10,10,13,13,2,0,73,73,105,105,2,0,70,70,102,102,1,0,48,57,1,0,
  	97,122,4,0,48,57,65,90,95,95,97,122,1,0,65,90,5,0,34,34,39,39,48,57,65,
  	90,97,122,7,0,34,34,92,92,98,98,102,102,108,108,110,110,116,116,4,0,45,
  	45,48,57,65,90,97,122,5,0,10,10,13,13,27,27,34,34,92,92,523,0,3,1,0,0,
  	0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,
  	1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,
  	0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,
  	0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,
  	1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,
  	0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,
  	0,69,1,0,0,0,0,71,1,0,0,0,0,73,1,0,0,0,0,75,1,0,0,0,0,77,1,0,0,0,0,79,
  	1,0,0,0,0,81,1,0,0,0,0,83,1,0,0,0,0,85,1,0,0,0,0,87,1,0,0,0,0,89,1,0,
  	0,0,0,91,1,0,0,0,0,93,1,0,0,0,0,95,1,0,0,0,0,97,1,0,0,0,0,99,1,0,0,0,
  	1,101,1,0,0,0,1,103,1,0,0,0,1,105,1,0,0,0,1,107,1,0,0,0,1,109,1,0,0,0,
  	1,111,1,0,0,0,1,113,1,0,0,0,1,115,1,0,0,0,1,117,1,0,0,0,1,119,1,0,0,0,
  	1,121,1,0,0,0,1,123,1,0,0,0,2,125,1,0,0,0,2,127,1,0,0,0,2,129,1,0,0,0,
  	2,131,1,0,0,0,3,133,1,0,0,0,5,135,1,0,0,0,7,138,1,0,0,0,9,140,1,0,0,0,
  	11,142,1,0,0,0,13,144,1,0,0,0,15,146,1,0,0,0,17,148,1,0,0,0,19,151,1,
  	0,0,0,21,153,1,0,0,0,23,155,1,0,0,0,25,157,1,0,0,0,27,159,1,0,0,0,29,
  	161,1,0,0,0,31,163,1,0,0,0,33,165,1,0,0,0,35,167,1,0,0,0,37,169,1,0,0,
  	0,39,172,1,0,0,0,41,189,1,0,0,0,43,191,1,0,0,0,45,202,1,0,0,0,47,207,
  	1,0,0,0,49,213,1,0,0,0,51,224,1,0,0,0,53,236,1,0,0,0,55,238,1,0,0,0,57,
  	251,1,0,0,0,59,257,1,0,0,0,61,259,1,0,0,0,63,266,1,0,0,0,65,284,1,0,0,
  	0,67,298,1,0,0,0,69,304,1,0,0,0,71,312,1,0,0,0,73,322,1,0,0,0,75,330,
  	1,0,0,0,77,338,1,0,0,0,79,344,1,0,0,0,81,354,1,0,0,0,83,364,1,0,0,0,85,
  	376,1,0,0,0,87,379,1,0,0,0,89,383,1,0,0,0,91,390,1,0,0,0,93,397,1,0,0,
  	0,95,399,1,0,0,0,97,404,1,0,0,0,99,410,1,0,0,0,101,412,1,0,0,0,103,418,
  	1,0,0,0,105,424,1,0,0,0,107,430,1,0,0,0,109,436,1,0,0,0,111,441,1,0,0,
  	0,113,447,1,0,0,0,115,453,1,0,0,0,117,458,1,0,0,0,119,465,1,0,0,0,121,
  	473,1,0,0,0,123,478,1,0,0,0,125,483,1,0,0,0,127,489,1,0,0,0,129,495,1,
  	0,0,0,131,499,1,0,0,0,133,134,5,59,0,0,134,4,1,0,0,0,135,136,5,61,0,0,
  	136,137,5,62,0,0,137,6,1,0,0,0,138,139,5,43,0,0,139,8,1,0,0,0,140,141,
  	5,45,0,0,141,10,1,0,0,0,142,143,5,47,0,0,143,12,1,0,0,0,144,145,5,42,
  	0,0,145,14,1,0,0,0,146,147,5,60,0,0,147,16,1,0,0,0,148,149,5,60,0,0,149,
  	150,5,61,0,0,150,18,1,0,0,0,151,152,5,61,0,0,152,20,1,0,0,0,153,154,5,
  	46,0,0,154,22,1,0,0,0,155,156,5,123,0,0,156,24,1,0,0,0,157,158,5,125,
  	0,0,158,26,1,0,0,0,159,160,5,40,0,0,160,28,1,0,0,0,161,162,5,41,0,0,162,
  	30,1,0,0,0,163,164,5,44,0,0,164,32,1,0,0,0,165,166,5,58,0,0,166,34,1,
  	0,0,0,167,168,5,64,0,0,168,36,1,0,0,0,169,170,5,126,0,0,170,38,1,0,0,
  	0,171,173,7,0,0,0,172,171,1,0,0,0,173,174,1,0,0,0,174,172,1,0,0,0,174,
  	175,1,0,0,0,175,176,1,0,0,0,176,177,6,18,0,0,177,40,1,0,0,0,178,179,5,
  	116,0,0,179,180,7,1,0,0,180,181,7,2,0,0,181,182,7,3,0,0,182,190,6,19,
  	1,0,183,184,5,102,0,0,184,185,7,4,0,0,185,186,7,5,0,0,186,187,7,6,0,0,
  	187,188,7,3,0,0,188,190,6,19,2,0,189,178,1,0,0,0,189,183,1,0,0,0,190,
  	42,1,0,0,0,191,192,5,45,0,0,192,193,5,45,0,0,193,197,1,0,0,0,194,196,
  	8,7,0,0,195,194,1,0,0,0,196,199,1,0,0,0,197,195,1,0,0,0,197,198,1,0,0,
  	0,198,200,1,0,0,0,199,197,1,0,0,0,200,201,6,20,0,0,201,44,1,0,0,0,202,
  	203,5,42,0,0,203,204,5,41,0,0,204,205,1,0,0,0,205,206,6,21,3,0,206,46,
  	1,0,0,0,207,208,5,40,0,0,208,209,5,42,0,0,209,210,1,0,0,0,210,211,6,22,
  	4,0,211,212,6,22,0,0,212,48,1,0,0,0,213,214,5,60,0,0,214,215,5,45,0,0,
  	215,50,1,0,0,0,216,217,5,99,0,0,217,218,5,97,0,0,218,219,5,115,0,0,219,
  	225,5,101,0,0,220,221,5,67,0,0,221,222,5,65,0,0,222,223,5,83,0,0,223,
  	225,5,69,0,0,224,216,1,0,0,0,224,220,1,0,0,0,225,52,1,0,0,0,226,227,5,
  	99,0,0,227,228,5,108,0,0,228,229,5,97,0,0,229,230,5,115,0,0,230,237,5,
  	115,0,0,231,232,5,67,0,0,232,233,5,76,0,0,233,234,5,65,0,0,234,235,5,
  	83,0,0,235,237,5,83,0,0,236,226,1,0,0,0,236,231,1,0,0,0,237,54,1,0,0,
  	0,238,239,7,3,0,0,239,240,7,5,0,0,240,241,7,6,0,0,241,242,7,3,0,0,242,
  	56,1,0,0,0,243,244,5,101,0,0,244,245,5,115,0,0,245,246,5,97,0,0,246,252,
  	5,99,0,0,247,248,5,69,0,0,248,249,5,83,0,0,249,250,5,65,0,0,250,252,5,
  	67,0,0,251,243,1,0,0,0,251,247,1,0,0,0,252,58,1,0,0,0,253,254,5,102,0,
  	0,254,258,5,105,0,0,255,256,5,70,0,0,256,258,5,73,0,0,257,253,1,0,0,0,
  	257,255,1,0,0,0,258,60,1,0,0,0,259,260,7,8,0,0,260,261,7,9,0,0,261,62,
  	1,0,0,0,262,263,5,105,0,0,263,267,5,110,0,0,264,265,5,73,0,0,265,267,
  	5,78,0,0,266,262,1,0,0,0,266,264,1,0,0,0,267,64,1,0,0,0,268,269,5,105,
  	0,0,269,270,5,110,0,0,270,271,5,104,0,0,271,272,5,101,0,0,272,273,5,114,
  	0,0,273,274,5,105,0,0,274,275,5,116,0,0,275,285,5,115,0,0,276,277,5,73,
  	0,0,277,278,5,78,0,0,278,279,5,72,0,0,279,280,5,69,0,0,280,281,5,82,0,
  	0,281,282,5,73,0,0,282,283,5,84,0,0,283,285,5,83,0,0,284,268,1,0,0,0,
  	284,276,1,0,0,0,285,66,1,0,0,0,286,287,5,105,0,0,287,288,5,115,0,0,288,
  	289,5,118,0,0,289,290,5,111,0,0,290,291,5,105,0,0,291,299,5,100,0,0,292,
  	293,5,73,0,0,293,294,5,83,0,0,294,295,5,86,0,0,295,296,5,79,0,0,296,297,
  	5,73,0,0,297,299,5,68,0,0,298,286,1,0,0,0,298,292,1,0,0,0,299,68,1,0,
  	0,0,300,301,5,108,0,0,301,305,5,101,0,0,302,303,5,76,0,0,303,305,5,69,
  	0,0,304,300,1,0,0,0,304,302,1,0,0,0,305,70,1,0,0,0,306,307,5,108,0,0,
  	307,308,5,101,0,0,308,313,5,116,0,0,309,310,5,76,0,0,310,311,5,69,0,0,
  	311,313,5,84,0,0,312,306,1,0,0,0,312,309,1,0,0,0,313,72,1,0,0,0,314,315,
  	5,108,0,0,315,316,5,111,0,0,316,317,5,111,0,0,317,323,5,112,0,0,318,319,
  	5,76,0,0,319,320,5,79,0,0,320,321,5,79,0,0,321,323,5,80,0,0,322,314,1,
  	0,0,0,322,318,1,0,0,0,323,74,1,0,0,0,324,325,5,110,0,0,325,326,5,101,
  	0,0,326,331,5,119,0,0,327,328,5,78,0,0,328,329,5,69,0,0,329,331,5,87,
  	0,0,330,324,1,0,0,0,330,327,1,0,0,0,331,76,1,0,0,0,332,333,5,110,0,0,
  	333,334,5,111,0,0,334,339,5,116,0,0,335,336,5,78,0,0,336,337,5,79,0,0,
  	337,339,5,84,0,0,338,332,1,0,0,0,338,335,1,0,0,0,339,78,1,0,0,0,340,341,
  	5,111,0,0,341,345,5,102,0,0,342,343,5,79,0,0,343,345,5,70,0,0,344,340,
  	1,0,0,0,344,342,1,0,0,0,345,80,1,0,0,0,346,347,5,112,0,0,347,348,5,111,
  	0,0,348,349,5,111,0,0,349,355,5,108,0,0,350,351,5,80,0,0,351,352,5,79,
  	0,0,352,353,5,79,0,0,353,355,5,76,0,0,354,346,1,0,0,0,354,350,1,0,0,0,
  	355,82,1,0,0,0,356,357,5,116,0,0,357,358,5,104,0,0,358,359,5,101,0,0,
  	359,365,5,110,0,0,360,361,5,84,0,0,361,362,5,72,0,0,362,363,5,69,0,0,
  	363,365,5,78,0,0,364,356,1,0,0,0,364,360,1,0,0,0,365,84,1,0,0,0,366,367,
  	5,119,0,0,367,368,5,104,0,0,368,369,5,105,0,0,369,370,5,108,0,0,370,377,
  	5,101,0,0,371,372,5,87,0,0,372,373,5,72,0,0,373,374,5,73,0,0,374,375,
  	5,76,0,0,375,377,5,69,0,0,376,366,1,0,0,0,376,371,1,0,0,0,377,86,1,0,
  	0,0,378,380,7,10,0,0,379,378,1,0,0,0,380,381,1,0,0,0,381,379,1,0,0,0,
  	381,382,1,0,0,0,382,88,1,0,0,0,383,387,7,11,0,0,384,386,7,12,0,0,385,
  	384,1,0,0,0,386,389,1,0,0,0,387,385,1,0,0,0,387,388,1,0,0,0,388,90,1,
  	0,0,0,389,387,1,0,0,0,390,394,7,13,0,0,391,393,7,12,0,0,392,391,1,0,0,
  	0,393,396,1,0,0,0,394,392,1,0,0,0,394,395,1,0,0,0,395,92,1,0,0,0,396,
  	394,1,0,0,0,397,398,8,14,0,0,398,94,1,0,0,0,399,400,5,95,0,0,400,401,
  	6,46,5,0,401,402,1,0,0,0,402,403,6,46,0,0,403,96,1,0,0,0,404,405,5,34,
  	0,0,405,406,6,47,6,0,406,407,1,0,0,0,407,408,6,47,7,0,408,409,6,47,0,
  	0,409,98,1,0,0,0,410,411,9,0,0,0,411,100,1,0,0,0,412,413,5,92,0,0,413,
  	414,5,10,0,0,414,415,6,49,8,0,415,416,1,0,0,0,416,417,6,49,0,0,417,102,
  	1,0,0,0,418,419,5,92,0,0,419,420,5,9,0,0,420,421,6,50,9,0,421,422,1,0,
  	0,0,422,423,6,50,0,0,423,104,1,0,0,0,424,425,5,92,0,0,425,426,5,12,0,
  	0,426,427,6,51,10,0,427,428,1,0,0,0,428,429,6,51,0,0,429,106,1,0,0,0,
  	430,431,5,92,0,0,431,432,5,8,0,0,432,433,6,52,11,0,433,434,1,0,0,0,434,
  	435,6,52,0,0,435,108,1,0,0,0,436,437,5,27,0,0,437,438,6,53,12,0,438,439,
  	1,0,0,0,439,440,6,53,0,0,440,110,1,0,0,0,441,442,5,92,0,0,442,443,7,15,
  	0,0,443,444,6,54,13,0,444,445,1,0,0,0,445,446,6,54,0,0,446,112,1,0,0,
  	0,447,448,5,92,0,0,448,449,5,0,0,0,449,450,6,55,14,0,450,451,1,0,0,0,
  	451,452,6,55,0,0,452,114,1,0,0,0,453,454,5,13,0,0,454,455,6,56,15,0,455,
  	456,1,0,0,0,456,457,6,56,0,0,457,116,1,0,0,0,458,459,5,92,0,0,459,460,
  	7,16,0,0,460,461,6,57,16,0,461,462,1,0,0,0,462,463,6,57,0,0,463,118,1,
  	0,0,0,464,466,8,17,0,0,465,464,1,0,0,0,466,467,1,0,0,0,467,465,1,0,0,
  	0,467,468,1,0,0,0,468,469,1,0,0,0,469,470,6,58,17,0,470,471,1,0,0,0,471,
  	472,6,58,0,0,472,120,1,0,0,0,473,474,5,10,0,0,474,475,6,59,18,0,475,476,
  	1,0,0,0,476,477,6,59,19,0,477,122,1,0,0,0,478,479,5,34,0,0,479,480,6,
  	60,20,0,480,481,1,0,0,0,481,482,6,60,19,0,482,124,1,0,0,0,483,484,5,40,
  	0,0,484,485,5,42,0,0,485,486,1,0,0,0,486,487,6,61,4,0,487,488,6,61,0,
  	0,488,126,1,0,0,0,489,490,5,42,0,0,490,491,5,41,0,0,491,492,1,0,0,0,492,
  	493,6,62,19,0,493,494,6,62,0,0,494,128,1,0,0,0,495,496,9,0,0,0,496,497,
  	1,0,0,0,497,498,6,63,0,0,498,130,1,0,0,0,499,500,9,0,0,0,500,501,5,0,
  	0,1,501,502,6,64,21,0,502,132,1,0,0,0,26,0,1,2,174,189,197,224,236,251,
  	257,266,284,298,304,312,322,330,338,344,354,364,376,381,387,394,467,22,
  	6,0,0,1,19,0,1,19,1,1,21,2,5,2,0,1,46,3,1,47,4,5,1,0,1,49,5,1,50,6,1,
  	51,7,1,52,8,1,53,9,1,54,10,1,55,11,1,56,12,1,57,13,1,58,14,1,59,15,4,
  	0,0,1,60,16,1,64,17
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  coollexerLexerStaticData = std::move(staticData);
}

}

CoolLexer::CoolLexer(CharStream *input) : Lexer(input) {
  CoolLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *coollexerLexerStaticData->atn, coollexerLexerStaticData->decisionToDFA, coollexerLexerStaticData->sharedContextCache);
}

CoolLexer::~CoolLexer() {
  delete _interpreter;
}

std::string CoolLexer::getGrammarFileName() const {
  return "CoolLexer.g4";
}

const std::vector<std::string>& CoolLexer::getRuleNames() const {
  return coollexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& CoolLexer::getChannelNames() const {
  return coollexerLexerStaticData->channelNames;
}

const std::vector<std::string>& CoolLexer::getModeNames() const {
  return coollexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& CoolLexer::getVocabulary() const {
  return coollexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CoolLexer::getSerializedATN() const {
  return coollexerLexerStaticData->serializedATN;
}

const atn::ATN& CoolLexer::getATN() const {
  return *coollexerLexerStaticData->atn;
}


void CoolLexer::action(RuleContext *context, size_t ruleIndex, size_t actionIndex) {
  switch (ruleIndex) {
    case 19: BOOL_CONSTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 21: UNMATCHED_COMMENT_ENDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 46: INVALID_UNDERSCOREAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 47: STRING_STARTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 49: STRING_NEW_LINE_SLASHAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 50: STRING_TABAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 51: STRING_FORMFEEDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 52: STRING_BACKSPACEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 53: STRING_ESCAPEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 54: STRING_ESC_SEQAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 55: STRING_ESC_SEQ_NULLAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 56: STRING_CARRIAGE_RETURNAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 57: STRING_SLASH_SYMBOLAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 58: STRING_NORMAL_CHARSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 59: STRING_NEW_LINE_UNESCPAEDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 60: STRING_ENDAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 64: UNCLOSED_COMMENT_AT_EOFAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

  default:
    break;
  }
}

void CoolLexer::BOOL_CONSTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 0:  assoc_bool_with_token(true);  break;
    case 1:  assoc_bool_with_token(false);  break;

  default:
    break;
  }
}

void CoolLexer::UNMATCHED_COMMENT_ENDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 2: 
            setType(ERROR);
            setText("Unmatched *)");
         break;

  default:
    break;
  }
}

void CoolLexer::INVALID_UNDERSCOREAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 3: 
            setType(ERROR);
            setText("Invalid symbol \"_\"");
         break;

  default:
    break;
  }
}

void CoolLexer::STRING_STARTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 4: 
        charCount = 0;
        null_Symbol = false;
        null_Symbol_ESCAPE = false;

        string_buffer.clear();
       break;

  default:
    break;
  }
}

void CoolLexer::STRING_NEW_LINE_SLASHAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 5: 
          charCount++;
          string_buffer.push_back('\\');
          string_buffer.push_back('n');
         break;

  default:
    break;
  }
}

void CoolLexer::STRING_TABAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 6: 
      charCount++;
      string_buffer.push_back('\\');
      string_buffer.push_back('t');
      break;

  default:
    break;
  }
}

void CoolLexer::STRING_FORMFEEDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 7: 
      charCount++;
      string_buffer.push_back('\\');
      string_buffer.push_back('f');
      break;

  default:
    break;
  }
}

void CoolLexer::STRING_BACKSPACEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 8: 
      charCount++;
      string_buffer.push_back('\\');
      string_buffer.push_back('b');
      break;

  default:
    break;
  }
}

void CoolLexer::STRING_ESCAPEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 9: 
      string_buffer.push_back('<');
      string_buffer.push_back('0');
      string_buffer.push_back('x');
      string_buffer.push_back('1');
      string_buffer.push_back('b');
      string_buffer.push_back('>');
      break;

  default:
    break;
  }
}

void CoolLexer::STRING_ESC_SEQAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 10: 
          charCount++;
          string_buffer.push_back('\\');
          string_buffer.push_back(getText()[1]);
         break;

  default:
    break;
  }
}

void CoolLexer::STRING_ESC_SEQ_NULLAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 11: 
          null_Symbol_ESCAPE = true;
         break;

  default:
    break;
  }
}

void CoolLexer::STRING_CARRIAGE_RETURNAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 12: 
      string_buffer.push_back('<');
      string_buffer.push_back('0');
      string_buffer.push_back('x');
      string_buffer.push_back('0');
      string_buffer.push_back('d');
      string_buffer.push_back('>');
      break;

  default:
    break;
  }
}

void CoolLexer::STRING_SLASH_SYMBOLAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 13: 
          charCount++;
          string_buffer.push_back(getText()[1]);
         break;

  default:
    break;
  }
}

void CoolLexer::STRING_NORMAL_CHARSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 14: 
          for (char c : getText())
          {
            charCount++;
            string_buffer.push_back(c);
          }
         break;

  default:
    break;
  }
}

void CoolLexer::STRING_NEW_LINE_UNESCPAEDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 15: 
        setType(ERROR);
        setText("String contains unescaped new line");
        charCount = 0;
      break;

  default:
    break;
  }
}

void CoolLexer::STRING_ENDAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 16: 

          for(char c : string_buffer){
            if(c == '\0'){
              null_Symbol = true;
            }
          }
          if(null_Symbol){
            setType(ERROR);
            setText("String contains null character");
          
          } else if (charCount > MAX_STR_CONST) {
            setType(ERROR);
            setText("String constant too long");
          }else if (null_Symbol_ESCAPE){
            setType(ERROR);
            setText("String contains escaped null character");
          } else {

            setType(STR_CONST);
            setText( "\"" +std::string(string_buffer.begin(), string_buffer.end())+ "\"");
          }
          charCount = 0;
         break;

  default:
    break;
  }
}

void CoolLexer::UNCLOSED_COMMENT_AT_EOFAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 17: 
                setType(ERROR);
                setText("Unmatched (*");
                popMode(); // clean up if necessary
             break;

  default:
    break;
  }
}



void CoolLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  coollexerLexerInitialize();
#else
  ::antlr4::internal::call_once(coollexerLexerOnceFlag, coollexerLexerInitialize);
#endif
}
