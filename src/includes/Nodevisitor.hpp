#ifndef FUEX_NODE_VISITOR_H
#define FUEX_NODE_VISITOR_H
#include <iostream>
#include "AST/AST_FunctionCall.hpp"
#include "AST/AST_String.hpp"
#include "AST/AST_Compound.hpp"
#include "AST/AST_NoOp.hpp"


class Nodevisitor {
    public:
        virtual AST* visit_AST_FunctionCall(AST_FunctionCall* node) = 0;
        virtual AST* visit_AST_String(AST_String* node) = 0;
        virtual AST* visit_AST_Compound(AST_Compound* node) = 0;
        virtual AST* visit_AST_NoOp(AST_NoOp* node) = 0;

        AST* visit(AST* node);
};
#endif
