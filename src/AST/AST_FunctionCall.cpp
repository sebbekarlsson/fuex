#include "../includes/AST/AST_FunctionCall.hpp"


AST_FunctionCall::AST_FunctionCall(std::string name, std::vector<AST*> args) {
    this->name = name;
    this->args = args;
};

AST_FunctionCall::~AST_FunctionCall() {};
