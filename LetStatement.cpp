//
// Created by Daniel Shih on 7/9/17.
//

#include "LetStatement.hpp"
#include "ProgramState.hpp"
#include <iostream>

LetStatement::LetStatement(std::string variableName, int value) {
    referencesExistingVariable = false;
    this->variableName = variableName;
    this->variableValue = value;
}

LetStatement::LetStatement(std::string variableName, std::string otherVariable) {
    referencesExistingVariable = true;
    this->variableName = variableName;
    this->otherVariableName = otherVariable;
}

void LetStatement::execute(ProgramState& state) const {
    if(referencesExistingVariable) {
        state.setVariableValue(variableName, state.getVariableValue(otherVariableName));
    } else {
        state.setVariableValue(variableName, variableValue);
    }
}