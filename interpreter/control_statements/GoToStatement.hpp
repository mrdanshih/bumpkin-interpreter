//
// Created by Daniel Shih on 12/25/17.
//

#ifndef BUMPKININTERPRETER_GOTOSTATEMENT_HPP
#define BUMPKININTERPRETER_GOTOSTATEMENT_HPP

#include "../Statement.hpp"
#include "../enumerations/LineLabelType.hpp"

class GoToStatement: public Statement {
public:
    //Set line to targetLineNumber
    GoToStatement(unsigned int lineNumber, std::string statementText, unsigned int targetLineNumber);

    //Set line to label
    GoToStatement(unsigned int lineNumber, std::string statementText, std::string lineLabel);

    virtual void execute(ProgramState& state) const override;

private:
    LineLabelType type;
    unsigned int targetLineNumber;
    std::string targetLineLabel;
};


#endif //BUMPKININTERPRETER_GOTOSTATEMENT_HPP
