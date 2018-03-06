#include "ComparisonValue.hpp"

ComparisonValue::ComparisonValue(int constant):
        constantValue{constant}, variableType{VALUE} {
}

ComparisonValue::ComparisonValue(std::string variableName):
        variable{variableName}, variableType{VARIABLE} {
}

VariableType ComparisonValue::getType() {
    return variableType;
}

int ComparisonValue::getConstantValue() {
    return constantValue;
}

std::string ComparisonValue::getVariableNameValue() {
    return variable;
}