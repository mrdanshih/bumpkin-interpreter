#ifndef BUMPKININTERPRETER_SUBSTATEMENT_HPP
#define BUMPKININTERPRETER_SUBSTATEMENT_HPP

#include "../Statement.hpp"
#include "../enumerations/VariableType.hpp"

class SubStatement: public Statement {
public:
    //Subtract value from variable
    SubStatement(unsigned int lineNumber, std::string statementText, std::string targetVariableName, int value);

    //Subtract value OF variable from a variable
    SubStatement(unsigned int lineNumber, std::string statementText, std::string targetVariableName, std::string otherVariable);

    virtual void execute(ProgramState& state) const override;

private:
    VariableType rValueType;
    std::string targetVariableName;
    std::string otherVariableName;
    int subtrahendValue;
};


#endif //BUMPKININTERPRETER_SUBSTATEMENT_HPP
