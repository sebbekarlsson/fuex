#ifndef FUEX_INTERPRETER_H
#define FUEX_INTERPRETER_H
#include "Nodevisitor.hpp"
#include "Lexer.hpp"
#include "Parser.hpp"
#include <vector>
#include <string>


class Interpreter: public Nodevisitor, Lexer {
    public:
        Interpreter(Parser* parser, std::string text);

        Parser* parser;

        anything visit_AST_FunctionCall(AST_FunctionCall* node);
        anything visit_AST_String(AST_String* node);
        anything visit_AST_Compound(AST_Compound* node);
        anything visit_AST_Group(AST_Group* node);
        anything visit_AST_NoOp(AST_NoOp* node);

        std::vector<std::string> matches;

        bool interpret();
};
#endif
