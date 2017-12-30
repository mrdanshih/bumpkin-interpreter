//
// Created by Daniel Shih on 12/29/17.
//

#ifndef BUMPKININTERPRETER_GOSUBSTATEMENT_HPP
#define BUMPKININTERPRETER_GOSUBSTATEMENT_HPP

#include "../Statement.hpp"
#include "../enumerations/LineLabelType.hpp"

class GoSubStatement: public Statement {
public:
    //Subroutine jump to line number
    GoSubStatement(unsigned int lineNumber);

    //Subroutine jump to line label
    GoSubStatement(std::string lineLabel);

    virtual void execute(ProgramState& state) const override;

private:
    LineLabelType type;
    unsigned int lineNumber;
    std::string lineLabel;
};


#endif //BUMPKININTERPRETER_GOSUBSTATEMENT_HPP
