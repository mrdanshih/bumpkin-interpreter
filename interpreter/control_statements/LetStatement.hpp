#ifndef BUMPKININTERPRETER_LETSTATEMENT_HPP
#define BUMPKININTERPRETER_LETSTATEMENT_HPP

#include "../Statement.hpp"
#include "../enumerations/VariableType.hpp"

class LetStatement: public Statement
{
public:
    //Set a variable to an int
    LetStatement(unsigned int lineNumber, std::string statementText, std::string variableName, int value);

    //Set a variable to the value of another variable
    LetStatement(unsigned int lineNumber, std::string statementText, std::string variableName, std::string otherVariable);

    virtual void execute(ProgramState& state) const override;

private:
    VariableType rValueType;
    std::string variableName;
    std::string otherVariableName;
    int variableValue;
};


#endif //BUMPKININTERPRETER_LETSTATEMENT_HPP
