#include "includes/Interpreter.hpp"
#include <iostream>
#include <sstream>


Interpreter::Interpreter(Parser* parser, std::string input_string) {
    this->parser = parser;
    this->input_string = input_string;
    this->pos = 0;
};

AST* Interpreter::visit_AST_FunctionCall(AST_FunctionCall* node) {
    while (
        this->input_string.at(this->pos) != '\0' &&
        this->pos < (int)this->input_string.size()
    ) {
        std::stringstream ss;
        std::string s;
        ss << this->input_string.at(this->pos);
        ss >> s;

        if (!isalnum(this->input_string.at(this->pos)))
            break;
        else
            std::cout << s << " = ok" << std::endl;

        this->pos++;
    }

    return new AST_NoOp();
};

AST* Interpreter::visit_AST_String(AST_String* node) {
    int i = 0;
    while (this->pos < (int)this->input_string.size()) {
        if (i >= (int)node->value.size())
            break;

        std::stringstream ss;
        std::string s;
        ss << this->input_string.at(this->pos);
        ss >> s;

        if (node->value.at(i) != this->input_string.at(this->pos)) {
            std::cout << s << " = ok" << std::endl;
        } else {
            std::cout << "unexpected: " + s << std::endl;
            this->pos++;
            break;
        }

        i++;
        this->pos++;
    }

    return new AST_NoOp();
};

AST* Interpreter::visit_AST_Compound(AST_Compound* node) {
    for (std::vector<AST*>::iterator it = node->children.begin(); it != node->children.end(); ++it)
        this->visit((*it));

    return new AST_NoOp();
};

AST* Interpreter::visit_AST_NoOp(AST_NoOp* node) {
    return nullptr;
};

bool Interpreter::interpret() {
    AST* tree = this->parser->parse();
    this->visit(tree);

    return true;
};
