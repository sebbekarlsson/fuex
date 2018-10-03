#include <iostream>
#include "includes/Lexer.hpp"
#include "includes/Parser.hpp"
#include "includes/Interpreter.hpp"


int main(int argc, char* argv[]) {

    Lexer* lexer = new Lexer(argv[1]);

    Parser* parser = new Parser(lexer);
    Interpreter* interpreter = new Interpreter(parser, argv[2]);
    interpreter->interpret();

    for (std::vector<std::string>::iterator it = interpreter->matches.begin(); it != interpreter->matches.end(); ++it) {
        std::cout << (*it) << std::endl;
    }

    return 0;
}
