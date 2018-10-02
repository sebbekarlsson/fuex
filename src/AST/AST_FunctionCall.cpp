#include "../includes/AST/AST_FunctionCall.hpp"


AST_FunctionCall::AST_FunctionCall(std::vector<Token*> args) {
    this->args = args;
};

AST_FunctionCall::~AST_FunctionCall() {};
