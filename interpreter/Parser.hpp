//
// Created by Daniel Shih on 9/7/17.
//

#ifndef BUMPKININTERPRETER_PARSER_HPP
#define BUMPKININTERPRETER_PARSER_HPP

#include <string>
#include <istream>
#include "ProgramState.hpp"
#include "LetStatement.hpp"
#include "PrintStatement.hpp"
#include "EndStatement.hpp"
#include "AddStatement.hpp"
#include "SubStatement.hpp"

class Parser
{
public:
    Parser();
    ProgramState getProgramState(std::istream* inputStream);
};

#endif //BUMPKININTERPRETER_PARSER_HPP
