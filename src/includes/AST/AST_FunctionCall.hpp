#ifndef FUEX_AST_FUNCTION_CALL_H
#define FUEX_AST_FUNCTION_CALL_H
#include "AST.hpp"
#include <vector>
#include <string>


class AST_FunctionCall: public AST {
    public:
        AST_FunctionCall(std::string name, std::vector<AST*> args);
        ~AST_FunctionCall();

        std::vector<AST*> args;

        std::string name;
};
#endif
