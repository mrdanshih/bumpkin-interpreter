//
// Created by Daniel Shih on 9/7/17.
//

#ifndef BUMPKININTERPRETER_PARSER_HPP
#define BUMPKININTERPRETER_PARSER_HPP

#include <string>
#include <istream>
#include "ProgramState.hpp"

class Parser
{
public:
    Parser(std::istream* inputStream);
    ProgramState getProgramState();
};

#endif //BUMPKININTERPRETER_PARSER_HPP
