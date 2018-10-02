#ifndef FUEX_PARSER_H
#define FUEX_PARSER_H
#include "AST/AST_FunctionCall.hpp"
#include "AST/AST_String.hpp"
#include "Token.hpp"
#include "Lexer.hpp"


class Parser {
    public:
        Parser(Lexer* lexer);

        Lexer* lexer;

        Token* current_token;

        void eat(std::string type);

        AST* any_statement();
        AST* statement();
        std::vector<AST*> statement_list();

        AST_FunctionCall* _function_call();
        AST_String* _string();

        AST* parse();
};
#endif
