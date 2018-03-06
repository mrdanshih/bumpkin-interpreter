#include "AddStatement.hpp"
#include "../ProgramState.hpp"

AddStatement::AddStatement(unsigned int lineNumber, std::string statementText,
                           std::string targetVariableName, int value)
        : Statement(lineNumber, statementText), rValueType{VALUE},
          targetVariableName{targetVariableName}, addendValue{value}
{
}

AddStatement::AddStatement(unsigned int lineNumber, std::string statementText,
                           std::string targetVariableName, std::string otherVariable)
        : Statement(lineNumber, statementText),
        rValueType{VARIABLE}, targetVariableName{targetVariableName},
        otherVariableName{otherVariable}
{
}

void AddStatement::execute(ProgramState& state) const {
    Statement::execute(state);

    switch(rValueType) {
        case VALUE:
            state.setVariableValue(targetVariableName,
                                   state.getVariableValue(targetVariableName) + addendValue);
            break;

        case VARIABLE:
            int rightAddendValue = state.getVariableValue(otherVariableName);
            state.setVariableValue(targetVariableName,
                                   state.getVariableValue(targetVariableName) + rightAddendValue);
            break;
    }
}
