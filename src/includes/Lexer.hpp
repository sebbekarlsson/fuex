#ifndef FUEX_LEXER_H
#define FUEX_LEXER_H
#include "Token.hpp"


class Lexer {
    public:
        Lexer(std::string text);

        std::string text;

        char current_char;

        int pos;

        Token* get_next_token();

        void advance();
        void skip_whitespace();
        
        std::string skip_char(char c, bool collect);
        std::string skip_until(char c, bool collect);

        char peek();
        char peek_until(int start_pos);

        Token* _id();
        Token* _string();
        Token* _integer();
};
#endif
