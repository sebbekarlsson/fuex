#ifndef FUEX_AST_GROUP_H
#define FUEX_AST_GROUP_H
#include "AST.hpp"
#include "AST_Compound.hpp"
#include <vector>
#include <string>


class AST_Group: public AST_Compound {
    public:
        AST_Group(std::string name, std::vector<AST*> children);
        ~AST_Group();

        std::string name;
};
#endif
