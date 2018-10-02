#ifndef FUEX_INTERPRETER_H
#define FUEX_INTERPRETER_H
#include "Nodevisitor.hpp"
#include "Lexer.hpp"
#include "Parser.hpp"


class Interpreter: public Nodevisitor {
    public:
        Interpreter(Parser* parser, std::string input_string);

        Parser* parser;
        std::string input_string;
        int pos;

        AST* visit_AST_FunctionCall(AST_FunctionCall* node);
        AST* visit_AST_String(AST_String* node);
        AST* visit_AST_Compound(AST_Compound* node);
        AST* visit_AST_NoOp(AST_NoOp* node);

        bool interpret();
};
#endif
