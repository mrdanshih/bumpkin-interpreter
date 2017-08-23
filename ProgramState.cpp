//
// Created by Daniel Shih on 7/9/17.
//

#include "ProgramState.hpp"

ProgramState::ProgramState(): programCounter{0} {

}

void ProgramState::addStatement(Statement* statement) {
    statements.push_back(statement);
}

void ProgramState::setVariableValue(const std::string& varName, int value) {
    // Store the value in the variableValues map
    variableValues[varName] = value;
}

void ProgramState::setVariableValue(const std::string& varName, const std::string& fromVar) {
    std::map<std::string, int>::iterator variablesIterator;
    variablesIterator = variableValues.find(fromVar);

    if(variablesIterator != variableValues.end()) {
        // If found the variable name in the map, set the varName variable to
        // the same value as the found variable name.
        variableValues[varName] = variablesIterator->second;
    }else{
        throw std::out_of_range("No variable with name " + varName);
    }
}

int ProgramState::getVariableValue(const std::string& varName) {
    std::map<std::string, int>::iterator variablesIterator;
    variablesIterator = variableValues.find(varName);

    if(variablesIterator != variableValues.end()) {
        return variableValues.at(varName);
    }else{
        throw std::out_of_range("No variable with name " + varName);
    }

}