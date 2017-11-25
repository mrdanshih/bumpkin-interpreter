//
// Created by Daniel Shih on 7/9/17.
//

#ifndef BUMPKININTERPRETER_STATEMENT_HPP
#define BUMPKININTERPRETER_STATEMENT_HPP

#include <string>

class ProgramState;

class Statement
{

public:
    virtual void execute(ProgramState& state) const = 0;
    virtual ~Statement() = default;
    virtual std::string trace();

private:
    int lineNumber;
    std::string statementText;

};
#endif //BUMPKININTERPRETER_STATEMENT_HPP
