//
// Created by Daniel Shih on 12/16/17.
//

#include "AddStatement.hpp"

AddStatement::AddStatement(std::string targetVariableName, int value):
    rValueType{VALUE}, targetVariableName{targetVariableName}, addendValue{value}
{
}

AddStatement::AddStatement(std::string targetVariableName, std::string otherVariable):
    rValueType{VARIABLE}, targetVariableName{targetVariableName},
    otherVariableName{otherVariable}
{
}

void AddStatement::execute(ProgramState& state) const {
    Statement::execute(state);

    switch(rValueType) {
        case VALUE:
            state.setVariableValue(targetVariableName,
                                   state.getVariableValue(targetVariableName) + addendValue);
            break;

        case VARIABLE:
            int rightAddendValue = state.getVariableValue(otherVariableName);
            state.setVariableValue(targetVariableName,
                                   state.getVariableValue(targetVariableName) + rightAddendValue);
            break;
    }
}
