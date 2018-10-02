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
        throw std::runtime_error(type);
    }
}

AST_FunctionCall* Parser::_function_call() {
    std::vector<Token*> args;
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

    return new AST_FunctionCall(args);
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

    this->current_token = this->lexer->get_next_token();

    return new AST_NoOp();
};

std::vector<AST*> Parser::statement_list() {
    std::vector<AST*> nodes;

    while (this->current_token->type != "EOF" && this->current_token->type != "SEMI") {
        nodes.push_back(this->statement());    
    };

    return nodes;
};

AST* Parser::parse() {
   return new AST_Compound(this->statement_list());
}
