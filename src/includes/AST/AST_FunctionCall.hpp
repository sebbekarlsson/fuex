#ifndef FUEX_AST_FUNCTION_CALL_H
#define FUEX_AST_FUNCTION_CALL_H
#include "AST.hpp"
#include "../Token.hpp"
#include <vector>


class AST_FunctionCall: public AST {
    public:
        AST_FunctionCall(std::string name, std::vector<Token*> args);
        ~AST_FunctionCall();

        std::vector<Token*> args;

        std::string name;
};
#endif
