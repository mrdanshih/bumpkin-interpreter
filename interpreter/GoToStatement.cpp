//
// Created by Daniel Shih on 12/25/17.
//

#include "GoToStatement.hpp"

GoToStatement::GoToStatement(std::string lineLabel):
        isTextLabel{true}, lineLabel{lineLabel}
{
}

GoToStatement::GoToStatement(unsigned int lineNumber):
    isTextLabel{false}, lineNumber{lineNumber}
{
}

void GoToStatement::execute(ProgramState &state) const {
    if(isTextLabel) {
        state.setProgramCounter(lineLabel);
    } else {
        state.setProgramCounter(lineNumber);
    }
}