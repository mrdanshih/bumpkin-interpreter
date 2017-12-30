//
// Created by Daniel Shih on 9/7/17.
//

#ifndef BUMPKININTERPRETER_PARSER_HPP
#define BUMPKININTERPRETER_PARSER_HPP

#include <string>
#include <istream>
#include <sstream>
#include <set>
#include <list>
#include "ProgramState.hpp"
#include "control_statements/LetStatement.hpp"
#include "control_statements/PrintStatement.hpp"
#include "control_statements/EndStatement.hpp"
#include "control_statements/GoToStatement.hpp"
#include "control_statements/GoSubStatement.hpp"
#include "control_statements/ReturnStatement.hpp"
#include "control_statements/IfStatement.hpp"
#include "arithmetic_statements/AddStatement.hpp"
#include "arithmetic_statements/SubStatement.hpp"
#include "arithmetic_statements/MultStatement.hpp"
#include "arithmetic_statements/DivStatement.hpp"
#include "enumerations/RelationalOperator.hpp"

class Parser
{
public:
    Parser();
    ProgramState getProgramState(std::istream* inputStream);
};

#endif //BUMPKININTERPRETER_PARSER_HPP
