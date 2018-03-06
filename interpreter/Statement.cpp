#include "Statement.hpp"
#include "ProgramState.hpp"

Statement::Statement(unsigned int lineNumber, std::string statementText)
    : lineNumber{lineNumber}, statementText{statementText}
{
}

std::ostream& operator << (std::ostream& out, const Statement& statement) {
    out << "||| " << statement.lineNumber << " | " << statement.statementText;
    return out;
}


void Statement::execute(ProgramState& state) const{
    state.incrementProgramCounter();
}