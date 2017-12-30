//
// Created by Daniel Shih on 12/16/17.
//

#ifndef BUMPKININTERPRETER_ENDSTATEMENT_HPP
#define BUMPKININTERPRETER_ENDSTATEMENT_HPP

#include "../Statement.hpp"

class EndStatement: public Statement {
public:
    virtual void execute(ProgramState& state) const override;
};


#endif //BUMPKININTERPRETER_ENDSTATEMENT_HPP
