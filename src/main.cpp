#include <iostream>
#include "includes/Lexer.hpp"
#include "includes/Parser.hpp"
#include "includes/Interpreter.hpp"


int main(int argc, char* argv[]) {

    Lexer* lexer = new Lexer(argv[1]);

    Parser* parser = new Parser(lexer);
    Interpreter* interpreter = new Interpreter(parser, argv[2]);
    interpreter->interpret();

    std::map<std::string, std::vector<std::string>>::iterator it;
    
    for (it = interpreter->matches.begin(); it != interpreter->matches.end(); it++) {
        std::string key = it->first;
        std::cout << "\"" + key + "\": [" << std::endl;
        for (std::vector<std::string>::iterator vit = (*it).second.begin(); vit != (*it).second.end(); ++vit) {
            std::cout << "\"" << (*vit) << "\"" << "," << std::endl;
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}
