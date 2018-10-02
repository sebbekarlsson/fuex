#include <iostream>
#include "includes/Lexer.hpp"


int main(int argc, char* argv[]) {

    Lexer* lexer = new Lexer("\"http\"+f_or(\"s\", \"\")+\":\\\"+f_or(\"www.\", fid)+\".\"+fid");

    while (lexer->current_char != '\0') {
        lexer->advance();
        std::cout << lexer->current_char << std::endl;
    }

    return 0;
}
