//
// Created by Daniel Shih on 12/18/17.
//

#ifndef BUMPKININTERPRETER_MULTSTATEMENT_HPP
#define BUMPKININTERPRETER_MULTSTATEMENT_HPP

#include "../Statement.hpp"
#include "../Type.hpp"

class MultStatement: public Statement {
public:
    //Multiply variable by a value
    MultStatement(std::string targetVariableName, int value);

    //Add value OF variable to a variable
    MultStatement(std::string targetVariableName, std::string otherVariable);

    virtual void execute(ProgramState& state) const override;

private:
    Type rValueType;
    std::string targetVariableName;
    std::string otherVariableName;
    int multiplicandValue;
};


#endif //BUMPKININTERPRETER_MULTSTATEMENT_HPP
