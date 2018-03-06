//
// Created by Daniel Shih on 12/29/17.
//

#include "GoSubStatement.hpp"
#include "../ProgramState.hpp"

GoSubStatement::GoSubStatement(unsigned int lineNumber, std::string statementText, std::string targetLineLabel):
        Statement(lineNumber, statementText),
        type{LABEL}, targetLineLabel{targetLineLabel}
{
}

GoSubStatement::GoSubStatement(unsigned int lineNumber, std::string statementText, unsigned int targetLineNumber):
        Statement(lineNumber, statementText),
        type{NUMBER}, targetLineNumber{targetLineNumber}
{
}

void GoSubStatement::execute(ProgramState &state) const {
    // Add current line number to the subroutine call stack.
    state.saveCurrentProgramCounter();

    if(type == LABEL) {
        state.setProgramCounter(targetLineLabel);
    } else {
        state.setProgramCounter(targetLineNumber);
    }
}