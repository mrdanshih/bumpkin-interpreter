//
// Created by Daniel Shih on 9/7/17.
//

#include "Parser.hpp"
#include <iostream>
#include <string>
#include <sstream>

namespace {
    bool has_only_digits(const std::string& s) {
        return s.find_first_not_of("0123456789") == std::string::npos;
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
        if(command == "LET") {
            std::string lvalue = tokens.at(1);
            std::string rvalue = tokens.at(2);
            return (has_only_digits(rvalue) ? new LetStatement(lvalue, std::stoi(rvalue)) : new LetStatement(lvalue, rvalue));

        } else if (command == "PRINT") {
            std::string rvalue = tokens.at(1);
            return (has_only_digits(rvalue) ? new PrintStatement(std::stoi(rvalue)) : new PrintStatement(rvalue));
        } else if (command == "END") {
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


