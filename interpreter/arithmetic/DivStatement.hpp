//
// Created by Daniel Shih on 12/18/17.
//

#ifndef BUMPKININTERPRETER_DIVSTATEMENT_HPP
#define BUMPKININTERPRETER_DIVSTATEMENT_HPP

#include "../Statement.hpp"
#include "../Type.hpp"

class DivStatement: public Statement {
public:
    //Divide variable by a value.
    DivStatement(std::string targetVariableName, int value);

    //Divide variable by value OF variable
    DivStatement(std::string targetVariableName, std::string otherVariable);

    virtual void execute(ProgramState& state) const override;

private:
    Type rValueType;
    std::string targetVariableName;
    std::string otherVariableName;
    int divisorValue;
};


#endif //BUMPKININTERPRETER_DIVSTATEMENT_HPP
