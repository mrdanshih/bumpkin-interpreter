#ifndef BUMPKININTERPRETER_ADDSTATEMENT_HPP
#define BUMPKININTERPRETER_ADDSTATEMENT_HPP

#include "../Statement.hpp"
#include "../enumerations/VariableType.hpp"


class AddStatement: public Statement {
public:
    //Add value to a variable
    AddStatement(unsigned int lineNumber, std::string statementText, std::string targetVariableName, int value);

    //Add value OF variable to a variable
    AddStatement(unsigned int lineNumber, std::string statementText, std::string targetVariableName, std::string otherVariable);

    virtual void execute(ProgramState& state) const override;

private:
    VariableType rValueType;
    std::string targetVariableName;
    std::string otherVariableName;
    int addendValue;
};


#endif //BUMPKININTERPRETER_ADDSTATEMENT_HPP
