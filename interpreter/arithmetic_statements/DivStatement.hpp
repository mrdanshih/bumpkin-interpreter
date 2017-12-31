//
// Created by Daniel Shih on 12/18/17.
//

#ifndef BUMPKININTERPRETER_DIVSTATEMENT_HPP
#define BUMPKININTERPRETER_DIVSTATEMENT_HPP

#include "../Statement.hpp"
#include "../enumerations/VariableType.hpp"

class DivStatement: public Statement {
public:
    //Divide variable by a value.
    DivStatement(unsigned int lineNumber, std::string statementText, std::string targetVariableName, int value);

    //Divide variable by value OF variable
    DivStatement(unsigned int lineNumber, std::string statementText, std::string targetVariableName, std::string otherVariable);

    virtual void execute(ProgramState& state) const override;

private:
    VariableType rValueType;
    std::string targetVariableName;
    std::string otherVariableName;
    int divisorValue;
};


#endif //BUMPKININTERPRETER_DIVSTATEMENT_HPP
