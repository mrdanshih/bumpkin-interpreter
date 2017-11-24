#include <iostream>
#include "ProgramState.hpp"
#include "LetStatement.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;
    ProgramState programState;
    LetStatement letStatement("A", 5);
    LetStatement secondLetStatement("B", 10);
    LetStatement third("B", "A");

    letStatement.execute(programState);
    std::cout << programState.getVariableValue("A") << std::endl;
    secondLetStatement.execute(programState);
    third.execute(programState);
    std::cout << programState.getVariableValue("B") << std::endl;

    return 0;
}

