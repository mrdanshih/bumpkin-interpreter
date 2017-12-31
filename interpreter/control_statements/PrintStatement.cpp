//
// Created by Daniel Shih on 11/23/17.
//

#include "PrintStatement.hpp"
#include <iostream>

PrintStatement::PrintStatement(unsigned int lineNumber, std::string statementText, int value):
        Statement(lineNumber, statementText), value{value}, itemType{VALUE}
{
}

PrintStatement::PrintStatement(unsigned int lineNumber, std::string statementText, std::string variableName):
        Statement(lineNumber, statementText),
        variableName{variableName}, itemType{VARIABLE}
{
}

void PrintStatement::execute(ProgramState& state) const {
    Statement::execute(state);
    switch(itemType) {
        case VALUE:
            std::cout << value << std::endl;
            break;
        case VARIABLE:
            std::cout << state.getVariableValue(variableName) << std::endl;
            break;
    }
}