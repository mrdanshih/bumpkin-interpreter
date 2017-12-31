//
// Created by Daniel Shih on 12/18/17.
//

#include "DivStatement.hpp"
#include "../BumpkinException.hpp"

DivStatement::DivStatement(unsigned int lineNumber, std::string statementText, std::string targetVariableName, int value):
        Statement(lineNumber, statementText),
        rValueType{VALUE}, targetVariableName{targetVariableName}, divisorValue{value}
{
}

DivStatement::DivStatement(unsigned int lineNumber, std::string statementText, std::string targetVariableName, std::string otherVariable):
        Statement(lineNumber, statementText),
        rValueType{VARIABLE}, targetVariableName{targetVariableName},
        otherVariableName{otherVariable}
{
}

void DivStatement::execute(ProgramState& state) const {
    Statement::execute(state);

    switch(rValueType) {
        case VALUE:
            if(divisorValue == 0) {
                throw BumpkinException("Division by zero");
            }

            state.setVariableValue(targetVariableName,
                                   state.getVariableValue(targetVariableName) / divisorValue);
            break;

        case VARIABLE:
            int divisorValue = state.getVariableValue(otherVariableName);

            if(divisorValue == 0) {
                throw BumpkinException("Division by zero");
            }

            state.setVariableValue(targetVariableName,
                                   state.getVariableValue(targetVariableName) / divisorValue);
            break;
    }
}