
// Generated from /home/student/my-code/cw2template/tools/../src/CoolParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "CoolParserVisitor.h"


/**
 * This class provides an empty implementation of CoolParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  CoolParserBaseVisitor : public CoolParserVisitor {
public:

  virtual std::any visitProgram(CoolParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClass(CoolParser::ClassContext *ctx) override {
    return visitChildren(ctx);
  }


};

