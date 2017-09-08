#include <iostream>
#include "ProgramState.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;
    ProgramState programState;
    programState.setVariableValue("A", 5);
    programState.setVariableValue("B", 10);
    programState.setVariableValue("A", "B");
    std::cout << programState.getVariableValue("A") << std::endl;

    return 0;
}

