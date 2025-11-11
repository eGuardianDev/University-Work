
// Generated from /home/student/my-code/cw2template/tools/../src/CoolParser.g4 by ANTLR 4.13.2


#include "CoolParserVisitor.h"

#include "CoolParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct CoolParserStaticData final {
  CoolParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CoolParserStaticData(const CoolParserStaticData&) = delete;
  CoolParserStaticData(CoolParserStaticData&&) = delete;
  CoolParserStaticData& operator=(const CoolParserStaticData&) = delete;
  CoolParserStaticData& operator=(CoolParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag coolparserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<CoolParserStaticData> coolparserParserStaticData = nullptr;

void coolparserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (coolparserParserStaticData != nullptr) {
    return;
  }
#else
  assert(coolparserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<CoolParserStaticData>(
    std::vector<std::string>{
      "program", "class"
    },
    std::vector<std::string>{
      "", "';'", "'{'", "'}'", "'('", "','", "')'", "':'", "'@'", "'.'", 
      "'+'", "'-'", "'*'", "'/'", "'~'", "'<'", "'='", "'=>'", "'<-'", "'<='", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "'--'", "", "'\\u003F'", "", "", "", 
      "", "", "", "", "", "", "", "", "", "'\\n'", "", "", "", "", "", "", 
      "'\\n'"
    },
    std::vector<std::string>{
      "", "SEMI", "OCURLY", "CCURLY", "OPAREN", "COMMA", "CPAREN", "COLON", 
      "AT", "DOT", "PLUS", "MINUS", "STAR", "SLASH", "TILDE", "LT", "EQ", 
      "DARROW", "ASSIGN", "LE", "CLASS", "ELSE", "FI", "IF", "IN", "INHERITS", 
      "ISVOID", "LET", "LOOP", "POOL", "THEN", "WHILE", "CASE", "ESAC", 
      "NEW", "OF", "NOT", "BOOL_CONST", "INT_CONST", "OBJECTID", "TYPEID", 
      "WS", "STR_BEGIN", "COMM_BEGIN", "COMM_ERR1", "LCOMM_BEGIN", "ERROR", 
      "STR_CONST", "STR_END", "STR_ESC_NL", "ESC_BS", "ESC_FF", "ESC_TAB", 
      "ESC_NULL", "ESC_ANY", "NULL", "STR_NL", "STR_ERR", "STR_ANY", "ESTR_END", 
      "ESTR_ESC_NL", "ESTR_NL", "ESTR_ANY", "OCOMM", "CCOMM", "COMM_SKIP", 
      "COMM_ERR", "LCOMM_END", "LCOMM_SKIP"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,68,17,2,0,7,0,2,1,7,1,1,0,1,0,1,0,4,0,8,8,0,11,0,12,0,9,1,1,1,1,1,
  	1,1,1,1,1,1,1,0,0,2,0,2,0,0,15,0,7,1,0,0,0,2,11,1,0,0,0,4,5,3,2,1,0,5,
  	6,5,1,0,0,6,8,1,0,0,0,7,4,1,0,0,0,8,9,1,0,0,0,9,7,1,0,0,0,9,10,1,0,0,
  	0,10,1,1,0,0,0,11,12,5,20,0,0,12,13,5,40,0,0,13,14,5,2,0,0,14,15,5,3,
  	0,0,15,3,1,0,0,0,1,9
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  coolparserParserStaticData = std::move(staticData);
}

}

CoolParser::CoolParser(TokenStream *input) : CoolParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

CoolParser::CoolParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  CoolParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *coolparserParserStaticData->atn, coolparserParserStaticData->decisionToDFA, coolparserParserStaticData->sharedContextCache, options);
}

CoolParser::~CoolParser() {
  delete _interpreter;
}

const atn::ATN& CoolParser::getATN() const {
  return *coolparserParserStaticData->atn;
}

std::string CoolParser::getGrammarFileName() const {
  return "CoolParser.g4";
}

const std::vector<std::string>& CoolParser::getRuleNames() const {
  return coolparserParserStaticData->ruleNames;
}

const dfa::Vocabulary& CoolParser::getVocabulary() const {
  return coolparserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CoolParser::getSerializedATN() const {
  return coolparserParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

CoolParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CoolParser::ClassContext *> CoolParser::ProgramContext::class_() {
  return getRuleContexts<CoolParser::ClassContext>();
}

CoolParser::ClassContext* CoolParser::ProgramContext::class_(size_t i) {
  return getRuleContext<CoolParser::ClassContext>(i);
}

std::vector<tree::TerminalNode *> CoolParser::ProgramContext::SEMI() {
  return getTokens(CoolParser::SEMI);
}

tree::TerminalNode* CoolParser::ProgramContext::SEMI(size_t i) {
  return getToken(CoolParser::SEMI, i);
}


size_t CoolParser::ProgramContext::getRuleIndex() const {
  return CoolParser::RuleProgram;
}


std::any CoolParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CoolParserVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

CoolParser::ProgramContext* CoolParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, CoolParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(7); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(4);
      class_();
      setState(5);
      match(CoolParser::SEMI);
      setState(9); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == CoolParser::CLASS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassContext ------------------------------------------------------------------

CoolParser::ClassContext::ClassContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CoolParser::ClassContext::CLASS() {
  return getToken(CoolParser::CLASS, 0);
}

tree::TerminalNode* CoolParser::ClassContext::TYPEID() {
  return getToken(CoolParser::TYPEID, 0);
}

tree::TerminalNode* CoolParser::ClassContext::OCURLY() {
  return getToken(CoolParser::OCURLY, 0);
}

tree::TerminalNode* CoolParser::ClassContext::CCURLY() {
  return getToken(CoolParser::CCURLY, 0);
}


size_t CoolParser::ClassContext::getRuleIndex() const {
  return CoolParser::RuleClass;
}


std::any CoolParser::ClassContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CoolParserVisitor*>(visitor))
    return parserVisitor->visitClass(this);
  else
    return visitor->visitChildren(this);
}

CoolParser::ClassContext* CoolParser::class_() {
  ClassContext *_localctx = _tracker.createInstance<ClassContext>(_ctx, getState());
  enterRule(_localctx, 2, CoolParser::RuleClass);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(11);
    match(CoolParser::CLASS);
    setState(12);
    match(CoolParser::TYPEID);
    setState(13);
    match(CoolParser::OCURLY);
    setState(14);
    match(CoolParser::CCURLY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void CoolParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  coolparserParserInitialize();
#else
  ::antlr4::internal::call_once(coolparserParserOnceFlag, coolparserParserInitialize);
#endif
}
