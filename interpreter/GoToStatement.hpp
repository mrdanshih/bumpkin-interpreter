//
// Created by Daniel Shih on 12/25/17.
//

#ifndef BUMPKININTERPRETER_GOTOSTATEMENT_HPP
#define BUMPKININTERPRETER_GOTOSTATEMENT_HPP

#include "Statement.hpp"

class GoToStatement: public Statement {
public:
    //Set line to
    GoToStatement(unsigned int lineNumber);

    //Set a variable to the value of another variable
    GoToStatement(std::string lineLabel);

    virtual void execute(ProgramState& state) const override;

private:
    bool isTextLabel;
    unsigned int lineNumber;
    std::string lineLabel;
};


#endif //BUMPKININTERPRETER_GOTOSTATEMENT_HPP
