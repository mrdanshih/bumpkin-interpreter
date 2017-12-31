//
// Created by Daniel Shih on 12/16/17.
//

#include "EndStatement.hpp"

EndStatement::EndStatement(unsigned int lineNumber, std::string statementText)
: Statement(lineNumber, statementText)
{
}

void EndStatement::execute(ProgramState &state) const {
    state.endProgram();
}