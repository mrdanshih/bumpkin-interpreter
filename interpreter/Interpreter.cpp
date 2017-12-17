//
// Created by Daniel Shih on 9/7/17.
//

#include "Interpreter.hpp"

Interpreter::Interpreter(const std::string &fileName){
    programFile.open(fileName);
}

void Interpreter::runProgram() {
    if(programFile.fail()) {
        throw std::string("ERROR: File was not opened!");
    }

    Parser p;
    ProgramState state = p.getProgramState(&programFile);

    while(!state.atProgramEnd()) {
        Statement* statement = state.getCurrentStatement();
        statement->execute(state);
    }
}