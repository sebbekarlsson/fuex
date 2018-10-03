#include "includes/Interpreter.hpp"
#include <iostream>
#include <sstream>


Interpreter::Interpreter(Parser* parser, std::string text) : Lexer(text) {
    this->parser = parser;
};

anything Interpreter::visit_AST_FunctionCall(AST_FunctionCall* node) {
    if (node->name == "id") {
        return this->_id()->value;
    } else if (node->name == "str") {
        return this->_string()->value;
    } else if (node->name == "w") {
        this->skip_whitespace();
    }

    return "";
};

anything Interpreter::visit_AST_String(AST_String* node) {
    std::string result = "";
    int i = 0;
    while (this->current_char == node->value.at(i)) {
        i++;
        result += this->current_char;
        this->advance();

        if (i >= (int)node->value.length())
            break;
    }

    if (result != node->value)
        this->pos += node->value.length() - 1;

    return result;
    return new AST_NoOp();
};

anything Interpreter::visit_AST_Compound(AST_Compound* node) {
    for (std::vector<AST*>::iterator it = node->children.begin(); it != node->children.end(); ++it)
        this->visit((*it));

    return new AST_NoOp();
};

anything Interpreter::visit_AST_Group(AST_Group* group) {
    std::string result = "";
    std::string tmpstring = "";

    for (std::vector<AST*>::iterator it = group->children.begin(); it != group->children.end(); ++it) {
        anything x = this->visit((*it));

        if (x.type() == typeid(std::string)) {
            tmpstring = boost::get<std::string>(x);

            if (!tmpstring.empty()) {
                result += tmpstring;
            } else {
                result = "";
                tmpstring = "";
                break;
            }
        }
    }

    if (!result.empty())
        this->matches[group->name].push_back(result);

    return result;
};

anything Interpreter::visit_AST_NoOp(AST_NoOp* node) {
    return nullptr;
};

int Interpreter::interpret() {
    AST* tree = this->parser->parse();

    while (this->current_char != '\0') {
        this->visit(tree);
        this->advance();
    }

    return this->matches.size();
};
