#ifndef FUEX_AST_COMPOUND_H
#define FUEX_AST_COMPOUND_H
#include "AST.hpp"
#include <vector>


class AST_Compound: public AST {
    public:
        AST_Compound(std::vector<AST*> children);
        ~AST_Compound();

        std::vector<AST*> children;
};
#endif
