//
// Created by Daniel Shih on 12/29/17.
//

#include "GoSubStatement.hpp"

GoSubStatement::GoSubStatement(std::string lineLabel):
        type{LABEL}, lineLabel{lineLabel}
{
}

GoSubStatement::GoSubStatement(unsigned int lineNumber):
        type{NUMBER}, lineNumber{lineNumber}
{
}

void GoSubStatement::execute(ProgramState &state) const {
    // Add current line number to the subroutine call stack.
    state.saveCurrentProgramCounter();

    if(type == LABEL) {
        state.setProgramCounter(lineLabel);
    } else {
        state.setProgramCounter(lineNumber);
    }
}