//
// Created by Daniel Shih on 12/28/17.
//

#ifndef BUMPKININTERPRETER_IFSTATEMENT_HPP
#define BUMPKININTERPRETER_IFSTATEMENT_HPP

#include "../Statement.hpp"
#include "../enumerations/RelationalOperator.hpp"
#include "../enumerations/LineLabelType.hpp"
#include "../ComparisonValue.hpp"

class IfStatement: public Statement {
public:
    //Compare value of two variables
    IfStatement(unsigned int lineNumber, std::string statementText,
                ComparisonValue leftValue, RelationalOperator compareOperator,
                ComparisonValue rightValue, std::string targetLineLabel);

    IfStatement(unsigned int lineNumber, std::string statementText,
                ComparisonValue leftValue, RelationalOperator compareOperator,
                ComparisonValue rightValue, unsigned int targetLineNumber);

    virtual void execute(ProgramState& state) const override;

private:
    ComparisonValue leftVal;
    ComparisonValue rightVal;
    RelationalOperator compareOperator;

    LineLabelType lineLabelType;
    unsigned int targetLineNumber;
    std::string targetLineLabel;
};


#endif //BUMPKININTERPRETER_IFSTATEMENT_HPP
