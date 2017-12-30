//
// Created by Daniel Shih on 12/18/17.
//

#include "MultStatement.hpp"


MultStatement::MultStatement(std::string targetVariableName, int value):
    rValueType{VALUE}, targetVariableName{targetVariableName}, multiplicandValue{value}
{
}

MultStatement::MultStatement(std::string targetVariableName, std::string otherVariable):
    rValueType{VARIABLE}, targetVariableName{targetVariableName},
    otherVariableName{otherVariable}
{
}

void MultStatement::execute(ProgramState& state) const {
    Statement::execute(state);

    switch(rValueType) {
        case VALUE:
            state.setVariableValue(targetVariableName,
                                   state.getVariableValue(targetVariableName) * multiplicandValue);
            break;

        case VARIABLE:
            int multiplicandValue = state.getVariableValue(otherVariableName);
            state.setVariableValue(targetVariableName,
                                   state.getVariableValue(targetVariableName) * multiplicandValue);
            break;
    }

}