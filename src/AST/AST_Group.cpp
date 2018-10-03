#include "../includes/AST/AST_Group.hpp"


AST_Group::AST_Group(std::string name, std::vector<AST*> children): AST_Compound(children) {
    this->name = name;
};

AST_Group::~AST_Group() {};
