//
// Created by Daniel Shih on 11/23/17.
//

#include "PrintStatement.hpp"
#include <iostream>

PrintStatement::PrintStatement(int value): value{value}, itemType{VALUE}
{
}

PrintStatement::PrintStatement(std::string variableName):
        variableName{variableName}, itemType{VARIABLE}
{
}

void PrintStatement::execute(ProgramState& state) const {
    switch(itemType) {
        case VALUE:
            std::cout << value << std::endl;
            break;
        case VARIABLE:
            std::cout << state.getVariableValue(variableName) << std::endl;
            break;
    }
}