//
// Created by Daniel Shih on 9/7/17.
//

#include "Parser.hpp"
#include <iostream>
#include <string>
#include <sstream>

namespace {
    bool has_only_digits(const std::string& s) {
        std::string stringToCheck = s;

        if(s.at(0) == '-') {
            stringToCheck.erase(0);
        }

        return stringToCheck.find_first_not_of("0123456789") == std::string::npos;
    }

    std::vector<std::string> getTokensForStatement(const std::string& line) {
        std::vector<std::string> statementTokens;
        std::stringstream ss{line};
        std::string token;

        while (ss >> token) {
            statementTokens.push_back(token);
        }

        return statementTokens;
    }

    Statement* getStatementFromTokens(const std::vector<std::string>& tokens) {
        std::string command = tokens.at(0);
        //Separate into two argument commands? three argument commands? etc.. else its too reptitive!

        if (command == "LET") {
            std::string lvalue = tokens.at(1);
            std::string rvalue = tokens.at(2);
            return (has_only_digits(rvalue) ? new LetStatement(lvalue, std::stoi(rvalue)) :
                    new LetStatement(lvalue, rvalue));

        } else if (command == "ADD") {
            std::string lvalue = tokens.at(1);
            std::string rvalue = tokens.at(2);
            return (has_only_digits(rvalue) ? new AddStatement(lvalue, std::stoi(rvalue)) :
                    new AddStatement(lvalue, rvalue));

        } else if (command == "SUB") {
            std::string lvalue = tokens.at(1);
            std::string rvalue = tokens.at(2);
            return (has_only_digits(rvalue) ? new SubStatement(lvalue, std::stoi(rvalue)) :
                    new SubStatement(lvalue, rvalue));

        } else if (command == "PRINT") {
            std::string rvalue = tokens.at(1);
            return (has_only_digits(rvalue) ? new PrintStatement(std::stoi(rvalue)) : new PrintStatement(rvalue));

        } else if (command == "END" || command == ".") {
            return new EndStatement();
        }

        throw std::string("This shouldn't happen!");
    }

}

Parser::Parser() {
}

ProgramState Parser::getProgramState(std::istream* inputStream) {
    // Build the program state in here
    ProgramState state;
    std::string line;

    while(std::getline(*inputStream, line)) {
        // For each line, parse into tokens.
        if(line.size() > 0) {
            std::vector<std::string> statementTokens = getTokensForStatement(line);

            // Based on tokens[0], make a new statement.
            Statement* statement = getStatementFromTokens(statementTokens);
            state.addStatement(statement);
        }
    }

    return state;
}


