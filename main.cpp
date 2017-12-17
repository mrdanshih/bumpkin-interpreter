#include <iostream>
#include <sstream>
#include <fstream>
#include "interpreter/ProgramState.hpp"
#include "interpreter/LetStatement.hpp"
#include "interpreter/PrintStatement.hpp"
#include "interpreter/Parser.hpp"
#include "interpreter/Interpreter.hpp"

int main() {
    Interpreter interpreter{"/Users/danielshih/CLionProjects/BumpkinInterpreter/test666.txt"};
    interpreter.runProgram();

    return 0;
}

