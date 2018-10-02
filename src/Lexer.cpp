#include "includes/Lexer.hpp"
#include <iostream>


Lexer::Lexer(std::string text) {
    this->text = text;
    this->pos = 0;
    this->current_char = this->text.at(this->pos);
};


Token* Lexer::get_next_token() {
    while (this->current_char != '\0') {
        if (this->current_char == ' ') {
            this->skip_whitespace();
            continue;
        }

        if (this->current_char == '"')
            return this->_string();

        if (isalpha(this->current_char))
            return this->_id();

        if (current_char == '(') {
            this->advance();
            return new Token("LPAREN", "(");
        }

        if (current_char == ')') {
            this->advance();
            return new Token("RPAREN", "");
        }
        
        this->advance();
        continue;
    }

    return new Token("EOF", "");
};

void Lexer::advance() {
    this->pos += 1;

    if (this->pos > (int)this->text.length() -1)
        this->current_char = '\0';
    else
        this->current_char = this->text.at(this->pos);
};

void Lexer::skip_whitespace() {
    while (this->current_char == ' ' || (int)this->current_char == 10)
        this->advance();
};

char Lexer::peek() {
    int peek_pos = this->pos + 1;

    if (peek_pos > (int)this->text.length()) {
        return '\0';
    }

    return this->text.at(peek_pos);
};

char Lexer::peek_until(int start_pos) {
    return ' ';
};

Token* Lexer::_id() {
    std::string result = "";

    while (this->current_char != '\0' && (isalnum(this->current_char) || this->current_char == '_')) {
        result += this->current_char;
        this->advance();
    }

    std::string type = "ID";

    if (current_char == '(')
        type = "FUNCTION_CALL";

    return new Token(type, result);
};

Token* Lexer::_string() {
    std::string result = "";

    this->advance();
    
    while (this->current_char != '"' && this->current_char != '\0') {
        result += this->current_char;
        this->advance();
    }

    this->advance();

    return new Token("STRING", result);
};

Token* Lexer::_integer() {
    return nullptr;
};
