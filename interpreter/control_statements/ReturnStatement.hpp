//
// Created by Daniel Shih on 12/29/17.
//

#ifndef BUMPKININTERPRETER_RETURNSTATEMENT_HPP
#define BUMPKININTERPRETER_RETURNSTATEMENT_HPP

#include "../Statement.hpp"
#include "../BumpkinException.hpp"

class ReturnStatement: public Statement {
public:
    ReturnStatement(unsigned int lineNumber, std::string statementText);
    virtual void execute(ProgramState& state) const override;
};


#endif //BUMPKININTERPRETER_RETURNSTATEMENT_HPP
