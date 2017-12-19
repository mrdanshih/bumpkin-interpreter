//
// Created by Daniel Shih on 12/16/17.
//

#ifndef BUMPKININTERPRETER_ADDSTATEMENT_HPP
#define BUMPKININTERPRETER_ADDSTATEMENT_HPP

#include "../Statement.hpp"
#include "../Type.hpp"


class AddStatement: public Statement {
public:
    //Add value to a variable
    AddStatement(std::string targetVariableName, int value);

    //Add value OF variable to a variable
    AddStatement(std::string targetVariableName, std::string otherVariable);

    virtual void execute(ProgramState& state) const override;

private:
    Type rValueType;
    std::string targetVariableName;
    std::string otherVariableName;
    int addendValue;
};


#endif //BUMPKININTERPRETER_ADDSTATEMENT_HPP
