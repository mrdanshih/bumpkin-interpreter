//
// Created by Daniel Shih on 12/17/17.
//

#include "SubStatement.hpp"

SubStatement::SubStatement(std::string targetVariableName, int value):
        rValueType{VALUE}, targetVariableName{targetVariableName}, subtrahendValue{value}
{
}

SubStatement::SubStatement(std::string targetVariableName, std::string otherVariable):
        rValueType{VARIABLE}, targetVariableName{targetVariableName},
        otherVariableName{otherVariable}
{
}

void SubStatement::execute(ProgramState& state) const {
    Statement::execute(state);

    switch(rValueType) {
        case VALUE:
            state.setVariableValue(targetVariableName,
                                   state.getVariableValue(targetVariableName) - subtrahendValue);
            break;

        case VARIABLE:
            int subtrahendValue = state.getVariableValue(otherVariableName);
            state.setVariableValue(targetVariableName,
                                   state.getVariableValue(targetVariableName) - subtrahendValue);
            break;
    }
}

