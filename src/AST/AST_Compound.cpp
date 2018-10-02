#include "../includes/AST/AST_Compound.hpp"


AST_Compound::AST_Compound(std::vector<AST*> children) {
    this->children = children;
};

AST_Compound::~AST_Compound() {};
