#ifndef BUMPKININTERPRETER_MULTSTATEMENT_HPP
#define BUMPKININTERPRETER_MULTSTATEMENT_HPP

#include "../Statement.hpp"
#include "../enumerations/VariableType.hpp"

class MultStatement: public Statement {
public:
    //Multiply variable by a value
    MultStatement(unsigned int lineNumber, std::string statementText, std::string targetVariableName, int value);

    //Add value OF variable to a variable
    MultStatement(unsigned int lineNumber, std::string statementText, std::string targetVariableName, std::string otherVariable);

    virtual void execute(ProgramState& state) const override;

private:
    VariableType rValueType;
    std::string targetVariableName;
    std::string otherVariableName;
    int multiplicandValue;
};


#endif //BUMPKININTERPRETER_MULTSTATEMENT_HPP
