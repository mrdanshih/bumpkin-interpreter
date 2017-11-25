//
// Created by Daniel Shih on 11/23/17.
//

#ifndef BUMPKININTERPRETER_PRINTSTATEMENT_HPP
#define BUMPKININTERPRETER_PRINTSTATEMENT_HPP

#include <string>
#include "Statement.hpp"
#include "ProgramState.hpp"
#include "Type.hpp"

class PrintStatement: public Statement
{
public:
    PrintStatement(int value);
    PrintStatement(std::string variableName);
    virtual void execute(ProgramState& state) const override;
private:
    std::string variableName;
    int value;
    Type itemType;
};


#endif //BUMPKININTERPRETER_PRINTSTATEMENT_HPP
