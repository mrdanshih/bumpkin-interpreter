#include <iostream>
#include <sstream>
#include <fstream>
#include "interpreter/ProgramState.hpp"
#include "interpreter/control_statements/LetStatement.hpp"
#include "interpreter/control_statements/PrintStatement.hpp"
#include "interpreter/Parser.hpp"
#include "interpreter/Interpreter.hpp"

int main() {
    try {
        Interpreter interpreter;
        interpreter.run();
    } catch (std::string s) {
        std::cout << s << std::endl;
    }

    return 0;
}

