//
// Created by Daniel Shih on 12/28/17.
//

#include "IfStatement.hpp"
#include <iostream>

namespace {
    int getActualValue(ComparisonValue compValue, ProgramState& state) {
        if(compValue.getType() == VARIABLE) {
            return state.getVariableValue(compValue.getVariableNameValue());
        } else {
            return compValue.getConstantValue();
        }

    }

    bool getTruthValue(int leftValue, int rightValue, RelationalOperator comparison) {
        switch(comparison) {
            case EQ:
                return leftValue == rightValue;
            case NOT_EQ:
                return leftValue != rightValue;
            case LESS:
                return leftValue < rightValue;
            case LESS_EQ:
                return leftValue <= rightValue;
            case GREATER:
                return leftValue > rightValue;
            case GREATER_EQ:
                return leftValue >= rightValue;
            default:
                throw std::string("THIS SHOULD NOT HAPPEN");
        }
    }
}

IfStatement::IfStatement(ComparisonValue leftValue, RelationalOperator compareOperator,
                         ComparisonValue rightValue, std::string lineLabel)
: leftVal{leftValue}, rightVal{rightValue}, compareOperator{compareOperator},
  lineLabel{lineLabel}, lineLabelType{LABEL}
{
}

IfStatement::IfStatement(ComparisonValue leftValue, RelationalOperator compareOperator,
                         ComparisonValue rightValue, unsigned int lineNumber)
        : leftVal{leftValue}, rightVal{rightValue}, compareOperator{compareOperator},
          lineNumber{lineNumber}, lineLabelType{NUMBER}
{
}

void IfStatement::execute(ProgramState& state) const {
    int leftActual = getActualValue(leftVal, state);
    int rightActual = getActualValue(rightVal, state);

    if(getTruthValue(leftActual, rightActual, compareOperator)) {
        if(lineLabelType == LABEL) {
            state.setProgramCounter(lineLabel);
        } else {
            state.setProgramCounter(lineNumber);
        }
    } else {
        Statement::execute(state);
    }
}