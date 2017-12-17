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
    Interpreter(const std::string& fileName);
    void runProgram();
private:
    std::ifstream programFile;
};

#endif //BUMPKININTERPRETER_INTERPRETER_HPP
