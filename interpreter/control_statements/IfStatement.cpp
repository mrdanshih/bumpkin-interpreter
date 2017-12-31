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

IfStatement::IfStatement(unsigned int lineNumber, std::string statementText,
                         ComparisonValue leftValue, RelationalOperator compareOperator,
                         ComparisonValue rightValue, std::string targetLineLabel)
: Statement(lineNumber, statementText),
  leftVal{leftValue}, rightVal{rightValue}, compareOperator{compareOperator},
  targetLineLabel{targetLineLabel}, lineLabelType{LABEL}
{
}

IfStatement::IfStatement(unsigned int lineNumber, std::string statementText,
                         ComparisonValue leftValue, RelationalOperator compareOperator,
                         ComparisonValue rightValue, unsigned int targetLineNumber)
        : Statement(lineNumber, statementText),
          leftVal{leftValue}, rightVal{rightValue}, compareOperator{compareOperator},
          targetLineNumber{targetLineNumber}, lineLabelType{NUMBER}
{
}

void IfStatement::execute(ProgramState& state) const {
    int leftActual = getActualValue(leftVal, state);
    int rightActual = getActualValue(rightVal, state);

    if(getTruthValue(leftActual, rightActual, compareOperator)) {
        if(lineLabelType == LABEL) {
            state.setProgramCounter(targetLineLabel);
        } else {
            state.setProgramCounter(targetLineNumber);
        }
    } else {
        Statement::execute(state);
    }
}