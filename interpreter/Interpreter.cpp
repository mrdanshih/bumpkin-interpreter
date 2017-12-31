//
// Created by Daniel Shih on 9/7/17.
//

#include "Interpreter.hpp"
#include "BumpkinException.hpp"


void Interpreter::run() {
    while(true) {
        std::cout << "> ";
        std::string command;
        std::getline(std::cin, command);

        std::vector<std::string> tokens;
        std::stringstream ss{command};
        std::string token;

        while (ss >> token) {
            tokens.push_back(token);
        }

        if(tokens.size() == 2 || tokens.size() == 1 && tokens.at(0) == "EXIT") {
            std::string& commandName = tokens.at(0);

            if(commandName == "EXIT") {
                break;
            } else if(commandName == "RUN" || commandName == "TRACE") {
                runProgram((commandName == "TRACE"), tokens.at(1));
            } else {
                std::cout << "UNRECOGNIZED COMMAND" << std::endl;
            }
        } else {
            std::cout << "UNRECOGNIZED COMMAND" << std::endl;
        }
    }
}

void Interpreter::runProgram(bool trace, std::string& fileName) {
    std::ifstream programFile;
    programFile.open(fileName);
    if(programFile.fail()) {
        throw std::string("ERROR: File was not opened!");
    }

    Parser p;
    ProgramState state = p.getProgramState(&programFile);

    while(!state.atProgramEnd()) {
        Statement* statement = state.getCurrentStatement();

        try {
            if(trace) {
                std::cout << *statement << std::endl;
            }
            statement->execute(state);
        } catch (BumpkinException& e) {
            std::cout << e.getMessage() << std::endl;
            return;
        }
    }
}