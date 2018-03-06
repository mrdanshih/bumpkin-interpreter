#include "MultStatement.hpp"
#include "../ProgramState.hpp"

MultStatement::MultStatement(unsigned int lineNumber, std::string statementText, std::string targetVariableName, int value):
        Statement(lineNumber, statementText),
        rValueType{VALUE}, targetVariableName{targetVariableName}, multiplicandValue{value}
{
}

MultStatement::MultStatement(unsigned int lineNumber, std::string statementText, std::string targetVariableName, std::string otherVariable):
        Statement(lineNumber, statementText),
        rValueType{VARIABLE}, targetVariableName{targetVariableName},
        otherVariableName{otherVariable}
{
}

void MultStatement::execute(ProgramState& state) const {
    Statement::execute(state);

    switch(rValueType) {
        case VALUE:
            state.setVariableValue(targetVariableName,
                                   state.getVariableValue(targetVariableName) * multiplicandValue);
            break;

        case VARIABLE:
            int multiplicandValue = state.getVariableValue(otherVariableName);
            state.setVariableValue(targetVariableName,
                                   state.getVariableValue(targetVariableName) * multiplicandValue);
            break;
    }

}