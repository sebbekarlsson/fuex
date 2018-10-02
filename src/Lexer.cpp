#include "includes/Lexer.hpp"


Lexer::Lexer(std::string text) {
    this->text = text;
    this->pos = 0;
};


Token* Lexer::get_next_token() {
    return nullptr;
};

void Lexer::advance() {
    // TODO: implement
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
