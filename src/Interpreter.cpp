#include "includes/Interpreter.hpp"
#include <iostream>
#include <sstream>


Interpreter::Interpreter(Parser* parser, std::string text) : Lexer(text) {
    this->parser = parser;
};

AST* Interpreter::visit_AST_FunctionCall(AST_FunctionCall* node) {
    std::string result = this->_id()->value;

    this->matches.push_back(result);
    return new AST_NoOp();
};

AST* Interpreter::visit_AST_String(AST_String* node) {
    std::string result = "";
    int i = 0;
    while (this->current_char == node->value.at(i)) {
        i++;
        result += this->current_char;
        this->advance();

        if (i >= node->value.length())
            break;
    }
    this->matches.push_back(result);
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
