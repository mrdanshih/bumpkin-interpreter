#include "EndStatement.hpp"
#include "../ProgramState.hpp"

EndStatement::EndStatement(unsigned int lineNumber, std::string statementText)
: Statement(lineNumber, statementText)
{
}

void EndStatement::execute(ProgramState &state) const {
    state.endProgram();
}