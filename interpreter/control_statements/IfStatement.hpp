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
    IfStatement(ComparisonValue leftValue, RelationalOperator compareOperator,
                ComparisonValue rightValue, std::string lineLabel);

    IfStatement(ComparisonValue leftValue, RelationalOperator compareOperator,
                ComparisonValue rightValue, unsigned int lineNumber);

    virtual void execute(ProgramState& state) const override;

private:
    ComparisonValue leftVal;
    ComparisonValue rightVal;
    RelationalOperator compareOperator;

    LineLabelType lineLabelType;
    unsigned int lineNumber;
    std::string lineLabel;
};


#endif //BUMPKININTERPRETER_IFSTATEMENT_HPP
