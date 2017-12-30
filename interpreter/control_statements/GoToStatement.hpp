//
// Created by Daniel Shih on 12/25/17.
//

#ifndef BUMPKININTERPRETER_GOTOSTATEMENT_HPP
#define BUMPKININTERPRETER_GOTOSTATEMENT_HPP

#include "../Statement.hpp"
#include "../enumerations/LineLabelType.hpp"

class GoToStatement: public Statement {
public:
    //Set line to lineNumber
    GoToStatement(unsigned int lineNumber);

    //Set line to label
    GoToStatement(std::string lineLabel);

    virtual void execute(ProgramState& state) const override;

private:
    LineLabelType type;
    unsigned int lineNumber;
    std::string lineLabel;
};


#endif //BUMPKININTERPRETER_GOTOSTATEMENT_HPP
