//
// Created by Daniel Shih on 7/9/17.
//

#include "LetStatement.hpp"


LetStatement::LetStatement(std::string variableName, int value):
        rValueType{VALUE}, variableName{variableName}, variableValue{value}
{
}

LetStatement::LetStatement(std::string variableName, std::string otherVariable):
    rValueType{VARIABLE}, variableName{variableName}, otherVariableName{otherVariable}
{
}

void LetStatement::execute(ProgramState& state) const {
    Statement::execute(state);

    switch(rValueType) {
        case VALUE:
            state.setVariableValue(variableName, variableValue);
            break;
        case VARIABLE:
            state.setVariableValue(variableName, state.getVariableValue(otherVariableName));
            break;
    }
}