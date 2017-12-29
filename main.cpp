#include <iostream>
#include <sstream>
#include <fstream>
#include "interpreter/ProgramState.hpp"
#include "interpreter/LetStatement.hpp"
#include "interpreter/PrintStatement.hpp"
#include "interpreter/Parser.hpp"
#include "interpreter/Interpreter.hpp"

int main() {
    try {
        Interpreter interpreter{"/Users/danielshih/CLionProjects/BumpkinInterpreter/input_files/goto_test.txt"};
        interpreter.runProgram();
    } catch (std::string s) {
        std::cout << s << std::endl;
    }

    return 0;
}

