//
// Created by Daniel Shih on 7/9/17.
//

#ifndef BUMPKININTERPRETER_PROGRAMSTATE_HPP
#define BUMPKININTERPRETER_PROGRAMSTATE_HPP

#include <string>
#include <map>
#include <vector>
#include "Statement.hpp"

class ProgramState
{
public:
    ProgramState();
    void addStatement(Statement* statement);
    void setVariableValue(const std::string& varName, int value);
    int getVariableValue(const std::string& varName);
    void incrementProgramCounter();

private:
    unsigned int programCounter;
    std::map<std::string, int> variableValues;
    // We need Statement pointers for polymorphism to work
    std::vector<Statement*> statements;

};
#endif //BUMPKININTERPRETER_PROGRAMSTATE_HPP
