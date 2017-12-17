//
// Created by Daniel Shih on 8/24/17.
//

#include "Statement.hpp"

std::string Statement::trace() {
    return std::to_string(lineNumber) + statementText;
}

void Statement::execute(ProgramState& state) const{
    state.incrementProgramCounter();
}