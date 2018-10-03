#include "../includes/AST/AST_Group.hpp"


AST_Group::AST_Group(std::vector<AST*> children): AST_Compound(children) {
};

AST_Group::~AST_Group() {};
