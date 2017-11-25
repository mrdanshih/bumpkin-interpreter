//
// Created by Daniel Shih on 9/7/17.
//

#include "Parser.hpp"
#include <iostream>

Parser::Parser(std::istream* inputStream) {
    // Build the program state in here
    std::string line;

    while(std::getline(*inputStream, line)) {
        std::cout << line << std::endl;
    }
}


ProgramState Parser::getProgramState() {

}
