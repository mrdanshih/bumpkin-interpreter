//
// Created by Daniel Shih on 7/9/17.
//

#ifndef BUMPKININTERPRETER_PROGRAMSTATE_HPP
#define BUMPKININTERPRETER_PROGRAMSTATE_HPP

#include <string>
#include <map>
#include <vector>
#include <stack>
#include <iostream>

class Statement;

class ProgramState
{
public:
    ProgramState();
    ~ProgramState();

    void addStatement(Statement* statement);
    void setVariableValue(const std::string& varName, int value);
    int getVariableValue(const std::string& varName);
    void incrementProgramCounter();
    void setProgramCounter(unsigned int line);
    void endProgram();

    Statement* getCurrentStatement();
    bool atProgramEnd();

private:
    unsigned int programCounter;
    std::map<std::string, int> variableValues;
    std::map<std::string, int> labelToLineNumbers;

    // Store stack of previous line numbers
    std::stack<int> subroutineStack;

    // We need Statement pointers for polymorphism to work
    std::vector<Statement*> statements;

};
#endif //BUMPKININTERPRETER_PROGRAMSTATE_HPP
