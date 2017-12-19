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
#include "LetStatement.hpp"
#include "PrintStatement.hpp"
#include "EndStatement.hpp"
#include "arithmetic/AddStatement.hpp"
#include "arithmetic/SubStatement.hpp"
#include "arithmetic/MultStatement.hpp"
#include "arithmetic/DivStatement.hpp"

class Parser
{
public:
    Parser();
    ProgramState getProgramState(std::istream* inputStream);
};

#endif //BUMPKININTERPRETER_PARSER_HPP
