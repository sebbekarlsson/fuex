#ifndef FUEX_AST_STRING_H
#define FUEX_AST_STRING_H
#include "AST.hpp"
#include <string>
#include <vector>


class AST_String: public AST {
    public:
        AST_String(std::string value);
        ~AST_String();

        std::string value;
};
#endif
