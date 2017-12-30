//
// Created by Daniel Shih on 12/16/17.
//

#include "EndStatement.hpp"

void EndStatement::execute(ProgramState &state) const {
    state.endProgram();
}