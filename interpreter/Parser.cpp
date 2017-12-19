//
// Created by Daniel Shih on 9/7/17.
//

#include "Parser.hpp"
#include <iostream>

namespace {
    bool has_only_digits(std::string s) {
        if(s.at(0) == '-') {
            s.erase(0);
        }
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
        //Separate into two argument commands? three argument commands? etc.. else its too reptitive!
        std::set<std::string> twoArgumentCommands = {"LET", "ADD", "SUB", "MULT", "DIV"};
        std::set<std::string> oneArgumentComnands = {"PRINT", "GOTO", "GOSUB"};

        if(twoArgumentCommands.find(command) != twoArgumentCommands.end()) {
            std::string lvalue = tokens.at(1);
            std::string rvalue = tokens.at(2);

            if (command == "LET") {
                return (has_only_digits(rvalue) ? new LetStatement(lvalue, std::stoi(rvalue)) :
                        new LetStatement(lvalue, rvalue));

            } else if (command == "ADD") {
                return (has_only_digits(rvalue) ? new AddStatement(lvalue, std::stoi(rvalue)) :
                        new AddStatement(lvalue, rvalue));

            } else if (command == "SUB") {
                return (has_only_digits(rvalue) ? new SubStatement(lvalue, std::stoi(rvalue)) :
                        new SubStatement(lvalue, rvalue));

            } else if (command == "MULT") {
                return (has_only_digits(rvalue) ? new MultStatement(lvalue, std::stoi(rvalue)) :
                        new MultStatement(lvalue, rvalue));

            } else if (command == "DIV") {
                return (has_only_digits(rvalue) ? new DivStatement(lvalue, std::stoi(rvalue)) :
                        new DivStatement(lvalue, rvalue));
            }

        } else if (oneArgumentComnands.find(command) != twoArgumentCommands.end()) {
            std::string rvalue = tokens.at(1);
            if (command == "PRINT") {
                return (has_only_digits(rvalue) ? new PrintStatement(std::stoi(rvalue)) : new PrintStatement(rvalue));
            }

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
    unsigned int lineNumber = 1;

    while(std::getline(*inputStream, line)) {
        // For each line, parse into tokens.
        if(line.size() > 0) {
            std::vector<std::string> statementTokens = getTokensForStatement(line);

            // Based on tokens[0], make a new statement.
            // Maybe here check for label by checking tokens[0] ending in ':'
            std::string& firstToken = statementTokens.at(0);
            if(firstToken.at(firstToken.size() - 1) == ':') {
                // associate line label
                state.setLineLabel(lineNumber, firstToken.substr(0, firstToken.size() - 1));
                statementTokens.erase(statementTokens.begin());
            }

            Statement* statement = getStatementFromTokens(statementTokens);
            state.addStatement(statement);
            ++lineNumber;
        }
    }

    return state;
}


