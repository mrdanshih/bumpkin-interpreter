//
// Created by Daniel Shih on 12/25/17.
//

#include "GoToStatement.hpp"

GoToStatement::GoToStatement(std::string lineLabel):
        type{LABEL}, lineLabel{lineLabel}
{
}

GoToStatement::GoToStatement(unsigned int lineNumber):
    type{NUMBER}, lineNumber{lineNumber}
{
}

void GoToStatement::execute(ProgramState &state) const {
    if(type == LABEL) {
        state.setProgramCounter(lineLabel);
    } else {
        state.setProgramCounter(lineNumber);
    }
}