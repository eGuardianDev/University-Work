
// Generated from /home/student/my-code/cw2template/tools/../src/CoolParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "CoolParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by CoolParser.
 */
class  CoolParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by CoolParser.
   */
    virtual std::any visitProgram(CoolParser::ProgramContext *context) = 0;

    virtual std::any visitClass(CoolParser::ClassContext *context) = 0;


};

