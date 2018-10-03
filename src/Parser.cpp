#include "includes/Parser.hpp"
#include "includes/AST/AST_Compound.hpp"
#include "includes/AST/AST_NoOp.hpp"
#include <iostream>


Parser::Parser(Lexer* lexer) {
    this->lexer = lexer;
    this->current_token = this->lexer->get_next_token();
};

void Parser::eat(std::string type) {
    if (type == this->current_token->type) {
        this->current_token = this->lexer->get_next_token();
    } else {
        throw std::runtime_error("Expected: " + type + ", got: " + this->current_token->type);
    }
}

AST_FunctionCall* Parser::_function_call() {
    std::vector<Token*> args;
    std::string name = this->current_token->value;
    this->eat("FUNCTION_CALL");
    this->eat("LPAREN");

    if (this->current_token->type == "ID") {
        this->eat("ID");
        args.push_back(this->current_token);
    }

    while (this->current_token->type == "COMMA") {
        this->eat("COMMA");
        this->eat("ID");
        args.push_back(this->current_token);
    }

    this->eat("RPAREN");

    return new AST_FunctionCall(name, args);
};

AST_String* Parser::_string() {
    AST_String* node = new AST_String(this->current_token->value);
    this->eat("STRING");

    return node;
};

AST* Parser::statement() {
    if (this->current_token->type == "FUNCTION_CALL")
        return this->_function_call();
    else if (this->current_token->type == "STRING")
        return this->_string();
    else if (this->current_token->type == "LBRACE")
        return this->_group();

    return new AST_NoOp();
};

std::vector<AST*> Parser::statement_list() {
    std::vector<AST*> nodes;

    nodes.push_back(this->statement());

    while (this->current_token->type != "EOF" && this->current_token->type != "SEMI") {
        nodes.push_back(this->statement());
    };

    if (this->current_token->type == "SEMI")
        this->eat("SEMI");

    return nodes;
};

AST_Group* Parser::_group() {
    AST_Group* group;
    std::vector<AST*> children;
    
    this->eat("LBRACE");
    while (this->current_token->type != "RBRACE")
        children.push_back(this->statement());

    this->eat("RBRACE");

    return new AST_Group(children);
};

AST* Parser::parse() {
   return new AST_Compound(this->statement_list());
}
