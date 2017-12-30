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


    Statement* getTwoArgumentStatement(std::string& command, std::string& lvalue, std::string& rvalue) {
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

        throw std::string("This shouldn't happen! - TWO ARGUMENT STATEMENTS");
    }

    Statement* getOneArgumentStatement(std::string& command, std::string& rvalue) {
        if (command == "PRINT") {
            return (has_only_digits(rvalue) ? new PrintStatement(std::stoi(rvalue)) : new PrintStatement(rvalue));

        } else if (command == "GOTO") {
            return (has_only_digits(rvalue) ?
                    new GoToStatement((unsigned int) std::stoi(rvalue)) : new GoToStatement(rvalue));

        } else if (command == "GOSUB") {
            return (has_only_digits(rvalue) ?
                    new GoSubStatement((unsigned int) std::stoi(rvalue)) : new GoSubStatement(rvalue));
        }
        throw std::string("This shouldn't happen! - ONE ARGUMENT STATEMENTS");
    }

    RelationalOperator getRelationalOperator(std::string& stringOperator) {
        if(stringOperator == "=") {
            return RelationalOperator::EQ;

        } else if (stringOperator == "<>") {
            return RelationalOperator::NOT_EQ;

        } else if (stringOperator == "<") {
            return RelationalOperator::LESS;

        } else if (stringOperator == "<=") {
            return RelationalOperator::LESS_EQ;

        } else if (stringOperator == ">") {
            return RelationalOperator::GREATER;

        } else {
            return RelationalOperator::GREATER_EQ;
        }

    }

    IfStatement* generateIfStatement(std::string& value1, std::string& op,
                                     std::string& value2, std::string lineLabel) {

        ComparisonValue compValue1 = (has_only_digits(value1) ? ComparisonValue{std::stoi(value1)} : ComparisonValue{value1});
        ComparisonValue compValue2 = (has_only_digits(value2) ? ComparisonValue{std::stoi(value2)} : ComparisonValue{value2});

        RelationalOperator relationalOp = getRelationalOperator(op);

        if(has_only_digits(lineLabel)) {
            return new IfStatement(compValue1, relationalOp, compValue2, (unsigned int) std::stoi(lineLabel));
        } else {
            return new IfStatement(compValue1, relationalOp, compValue2, lineLabel);
        }
    }

    Statement* getStatementFromTokens(const std::vector<std::string>& tokens) {
        std::string command = tokens.at(0);
        //Separate into two argument commands? three argument commands? etc.. else its too reptitive!
        std::set<std::string> twoArgumentCommands = {"LET", "ADD", "SUB", "MULT", "DIV"};
        std::set<std::string> oneArgumentCommands = {"PRINT", "GOTO", "GOSUB"};

        if (twoArgumentCommands.find(command) != twoArgumentCommands.end()) {
            std::string lvalue = tokens.at(1);
            std::string rvalue = tokens.at(2);

            return getTwoArgumentStatement(command, lvalue, rvalue);

        } else if (oneArgumentCommands.find(command) != oneArgumentCommands.end()) {
            std::string rvalue = tokens.at(1);

            return getOneArgumentStatement(command, rvalue);

        } else if (command == "IF") {
            std::string value1 = tokens.at(1);
            std::string op = tokens.at(2);
            std::string value2 = tokens.at(3);
            std::string line = tokens.at(5);

            return generateIfStatement(value1, op, value2, line);

        } else if (command == "END" || command == ".") {
            return new EndStatement();

        } else if (command == "RETURN") {
            return new ReturnStatement();
        }

        throw std::string("This shouldn't happen! - TOKENS PARSER");
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


