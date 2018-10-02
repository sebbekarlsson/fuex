#include <iostream>
#include "includes/Lexer.hpp"
#include "includes/Parser.hpp"
#include "includes/Interpreter.hpp"


int main(int argc, char* argv[]) {

    Lexer* lexer = new Lexer("\"www.\"id()");

    Parser* parser = new Parser(lexer);
    Interpreter* interpreter = new Interpreter(parser, "hello.com 12");

    interpreter->interpret();

    return 0;
}
