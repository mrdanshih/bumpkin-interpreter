#ifndef BUMPKININTERPRETER_GOSUBSTATEMENT_HPP
#define BUMPKININTERPRETER_GOSUBSTATEMENT_HPP

#include "../Statement.hpp"
#include "../enumerations/LineLabelType.hpp"

class GoSubStatement: public Statement {
public:
    //Subroutine jump to line number
    GoSubStatement(unsigned int lineNumber, std::string statementText, unsigned int targetLineNumber);

    //Subroutine jump to line label
    GoSubStatement(unsigned int lineNumber, std::string statementText, std::string targetLineLabel);

    virtual void execute(ProgramState& state) const override;

private:
    LineLabelType type;
    unsigned int targetLineNumber;
    std::string targetLineLabel;
};


#endif //BUMPKININTERPRETER_GOSUBSTATEMENT_HPP
