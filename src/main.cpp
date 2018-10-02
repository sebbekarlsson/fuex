#include <iostream>
#include "includes/Lexer.hpp"


int main(int argc, char* argv[]) {

    Lexer* lexer = new Lexer("\"http\"+f_or(\"s\", \"\")+\":\\\\\"+f_or(\"www.\", fid)+\".\"+fid");

    Token* token = new Token("", "");

    while (token->type != "EOF") {
        token = lexer->get_next_token();
        std::cout << token->value << std::endl;
    }

    return 0;
}
