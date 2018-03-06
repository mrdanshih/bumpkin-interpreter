#ifndef BUMPKININTERPRETER_ENDSTATEMENT_HPP
#define BUMPKININTERPRETER_ENDSTATEMENT_HPP

#include "../Statement.hpp"

class EndStatement: public Statement {
public:
    EndStatement(unsigned int lineNumber, std::string statementText);
    virtual void execute(ProgramState& state) const override;
};


#endif //BUMPKININTERPRETER_ENDSTATEMENT_HPP
