#include "includes/Nodevisitor.hpp"


AST* Nodevisitor::visit(AST* node) {
    if (dynamic_cast<AST_Compound*>( node )) {
        return this->visit_AST_Compound((AST_Compound*)node);
    }

    if (dynamic_cast<AST_FunctionCall*>( node )) {
        return this->visit_AST_FunctionCall((AST_FunctionCall*)node);
    }

    if (dynamic_cast<AST_String*>( node )) {
        return this->visit_AST_String((AST_String*)node);
    }

    if (dynamic_cast<AST_NoOp*>( node )) {
        return this->visit_AST_NoOp((AST_NoOp*)node);
    }

    std::cout << "visiting unknown" << std::endl;
    return nullptr;
}
