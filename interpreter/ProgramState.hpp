#ifndef BUMPKININTERPRETER_PROGRAMSTATE_HPP
#define BUMPKININTERPRETER_PROGRAMSTATE_HPP

#include <string>
#include <map>
#include <vector>
#include <stack>
#include <iostream>
#include "Statement.hpp"
#include "BumpkinException.hpp"
class Statement;
class ProgramState
{
public:
    ProgramState();
    ~ProgramState();

    void addStatement(Statement* statement);
    Statement* getCurrentStatement();

    void setVariableValue(const std::string& varName, int value);
    int getVariableValue(const std::string& varName);

    void incrementProgramCounter();
    void setProgramCounter(unsigned int line);
    void setProgramCounter(const std::string& label);
    unsigned int getProgramCounter();

    void saveCurrentProgramCounter();   // For sub-routine - remember the current PC on call stack
    void restoreMostRecentProgramCounter();     // Get the last program counter.
    bool hasSavedProgramCounters();

    void setLineLabel(unsigned int lineNumber, const std::string& label);
    unsigned int getLineNumber(const std::string& label);

    void endProgram();

    bool atProgramEnd();

private:
    unsigned int programCounter;
    std::map<std::string, int> variableValues;
    std::map<std::string, unsigned int> labelToLineNumbers;

    // Store stack of previous line numbers
    std::stack<unsigned int> subroutineStack;

    // We need Statement pointers for polymorphism to work
    std::vector<Statement*> statements;

};
#endif //BUMPKININTERPRETER_PROGRAMSTATE_HPP
