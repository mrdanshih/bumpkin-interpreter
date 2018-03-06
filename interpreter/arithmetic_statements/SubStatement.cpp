//
// Created by Daniel Shih on 12/17/17.
//

#include "SubStatement.hpp"
#include "../ProgramState.hpp"

SubStatement::SubStatement(unsigned int lineNumber, std::string statementText, std::string targetVariableName, int value):
        Statement(lineNumber, statementText),
        rValueType{VALUE}, targetVariableName{targetVariableName}, subtrahendValue{value}
{
}

SubStatement::SubStatement(unsigned int lineNumber, std::string statementText, std::string targetVariableName, std::string otherVariable):
        Statement(lineNumber, statementText),
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

