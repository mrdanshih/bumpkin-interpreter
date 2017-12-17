//
// Created by Daniel Shih on 7/9/17.
//

#ifndef BUMPKININTERPRETER_STATEMENT_HPP
#define BUMPKININTERPRETER_STATEMENT_HPP

#include <string>
#include "ProgramState.hpp"

class Statement
{

public:
    virtual void execute(ProgramState& state) const;
    virtual ~Statement() = default;
    virtual std::string trace();


private:
    int lineNumber;
    std::string statementText;

};
#endif //BUMPKININTERPRETER_STATEMENT_HPP
