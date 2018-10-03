#ifndef FUEX_NODE_VISITOR_H
#define FUEX_NODE_VISITOR_H
#include <iostream>
#include "AST/AST_FunctionCall.hpp"
#include "AST/AST_String.hpp"
#include "AST/AST_Compound.hpp"
#include "AST/AST_Group.hpp"
#include "AST/AST_NoOp.hpp"
#include "typedefs.hpp"


class Nodevisitor {
    public:
        virtual anything visit_AST_FunctionCall(AST_FunctionCall* node) = 0;
        virtual anything visit_AST_String(AST_String* node) = 0;
        virtual anything visit_AST_Compound(AST_Compound* node) = 0;
        virtual anything visit_AST_Group(AST_Group* node) = 0;
        virtual anything visit_AST_NoOp(AST_NoOp* node) = 0;

        anything visit(AST* node);
};
#endif
