//
// Created by Daniel Shih on 7/9/17.
//

#include "LetStatement.hpp"
#include "../ProgramState.hpp"


LetStatement::LetStatement(unsigned int lineNumber, std::string statementText,
                           std::string variableName, int value):
        Statement(lineNumber, statementText),
        rValueType{VALUE}, variableName{variableName}, variableValue{value}
{
}

LetStatement::LetStatement(unsigned int lineNumber, std::string statementText,
                           std::string variableName, std::string otherVariable):
        Statement(lineNumber, statementText),
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