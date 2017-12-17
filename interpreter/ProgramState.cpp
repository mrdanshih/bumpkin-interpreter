//
// Created by Daniel Shih on 7/9/17.
//

#include "ProgramState.hpp"


ProgramState::ProgramState(): programCounter{1}{
    //Store null in 0th cell
    statements.push_back(nullptr);

}

ProgramState::~ProgramState() {
    // Need to delete all the dynamically allocated Statements
    for(Statement* statement: statements) {
        delete statement;
    }
}

void ProgramState::addStatement(Statement* statement) {
    statements.push_back(statement);
}

void ProgramState::setVariableValue(const std::string& varName, int value) {
    // Store the value in the variableValues map
    variableValues[varName] = value;
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

void ProgramState::incrementProgramCounter() {
    programCounter++;
}

void ProgramState::setProgramCounter(unsigned int line) {
    programCounter = line;
}

void ProgramState::endProgram() {
    // Make program counter == size, which means the end of program.
    programCounter = (int) statements.size();
}

bool ProgramState::atProgramEnd() {
    return programCounter >= statements.size();
}

Statement* ProgramState::getCurrentStatement() {
    return statements.at(programCounter);
}

