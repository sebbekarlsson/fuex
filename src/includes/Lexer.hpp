#ifndef FUEX_LEXER_H
#define FUEX_LEXER_H
#include "Token.hpp"


class Lexer {
    public:
        Lexer(std::string text);

        std::string text;
        
        int pos;

        Token* get_next_token();

        void advance();

        char peek();
        char peek_until(int start_pos);

        std::string _id();
        std::string _string();
        int _integer();
};
#endif
