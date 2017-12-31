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

Statement* ProgramState::getCurrentStatement() {
    return statements.at(programCounter);
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
        return 0;
    }
}

void ProgramState::incrementProgramCounter() {
    programCounter++;
}

void ProgramState::setProgramCounter(unsigned int line) {
    if(line < 1 || line > statements.size()) {
        throw BumpkinException("Line number out of bounds");
    }

    programCounter = line;
}

void ProgramState::setProgramCounter(const std::string& label) {
    if(labelToLineNumbers.find(label) == labelToLineNumbers.end()) {
        throw BumpkinException("Non-existent label " + label);
    }
    programCounter = labelToLineNumbers.at(label);
}

unsigned int ProgramState::getProgramCounter() {
    return programCounter;
}

void ProgramState::setLineLabel(unsigned int lineNumber, const std::string& label) {
    labelToLineNumbers[label] = lineNumber;
}

unsigned int ProgramState::getLineNumber(const std::string& label) {
    return labelToLineNumbers.at(label);
}

void ProgramState::saveCurrentProgramCounter() {
    subroutineStack.push(programCounter);
}

void ProgramState::restoreMostRecentProgramCounter() {
    programCounter = subroutineStack.top();
    subroutineStack.pop();
}

bool ProgramState::hasSavedProgramCounters() {
    return !subroutineStack.empty();
}

void ProgramState::endProgram() {
    // Make program counter == size, which means the end of program.
    programCounter = (int) statements.size();
}

bool ProgramState::atProgramEnd() {
    return programCounter >= statements.size();
}


