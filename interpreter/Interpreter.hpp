//
// Created by Daniel Shih on 9/7/17.
//

#ifndef BUMPKININTERPRETER_INTERPRETER_HPP
#define BUMPKININTERPRETER_INTERPRETER_HPP

#include <string>
#include <fstream>
#include "Parser.hpp"

class Interpreter {
public:
    void run();

private:
    void runProgram(bool trace, std::istream* programStream);
    std::stringstream takeProgramInput();
};

#endif //BUMPKININTERPRETER_INTERPRETER_HPP
