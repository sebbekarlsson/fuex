#include "includes/Lexer.hpp"


Lexer::Lexer(std::string text) {
    this->text = text;
    this->pos = 0;
    this->current_char = this->text.at(this->pos);
};


Token* Lexer::get_next_token() {
    return nullptr;
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
    return ' ';
};

char Lexer::peek_until(int start_pos) {
    return ' ';
};

std::string Lexer::_id() {
    return "";
};

std::string Lexer::_string() {
    return "";
};

int Lexer::_integer() {
    return 0;
};
