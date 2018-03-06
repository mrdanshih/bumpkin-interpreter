//
// Created by Daniel Shih on 12/25/17.
//

#include "GoToStatement.hpp"
#include "../ProgramState.hpp"

GoToStatement::GoToStatement(unsigned int lineNumber, std::string statementText, std::string lineLabel)
        : Statement(lineNumber, statementText),
        type{LABEL}, targetLineLabel{lineLabel}
{
}

GoToStatement::GoToStatement(unsigned int lineNumber, std::string statementText, unsigned int targetLineNumber)
        : Statement(lineNumber, statementText),
    type{NUMBER}, targetLineNumber{targetLineNumber}
{
}

void GoToStatement::execute(ProgramState &state) const {
    if(type == LABEL) {
        state.setProgramCounter(targetLineLabel);
    } else {
        state.setProgramCounter(targetLineNumber);
    }
}