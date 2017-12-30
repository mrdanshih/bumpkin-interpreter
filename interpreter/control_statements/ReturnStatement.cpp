//
// Created by Daniel Shih on 12/29/17.
//

#include "ReturnStatement.hpp"

void ReturnStatement::execute(ProgramState &state) const {
    if(state.hasSavedProgramCounters()) {
        state.restoreMostRecentProgramCounter();
        Statement::execute(state);
    } else {
        throw BumpkinException("No corresponding GOSUB");
    }

}