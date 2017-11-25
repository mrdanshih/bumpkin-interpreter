#include <iostream>
#include <sstream>
#include "interpreter/ProgramState.hpp"
#include "interpreter/LetStatement.hpp"
#include "interpreter/PrintStatement.hpp"
#include "interpreter/Parser.hpp"

int main() {
//    std::cout << "Hello, World!" << std::endl;
//    ProgramState programState;
//    LetStatement letStatement("A", 5);
//    LetStatement secondLetStatement("B", 10);
//    LetStatement third("B", "A");
//    PrintStatement printStatement("B");
//    letStatement.execute(programState);
//    std::cout << programState.getVariableValue("A") << std::endl;
//    secondLetStatement.execute(programState);
//    third.execute(programState);
//    printStatement.execute(programState);
//    std::cout << programState.getVariableValue("B") << std::endl;
    std::string test = "ABC\nHello there!";
    std::stringstream testStream(test);
    Parser p(&testStream);

    return 0;
}

