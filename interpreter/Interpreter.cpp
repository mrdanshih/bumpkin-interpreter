//
// Created by Daniel Shih on 9/7/17.
//

#include "Interpreter.hpp"


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

        if(tokens.size() == 1 || tokens.size() == 2) {
            std::string& commandName = tokens.at(0);

            if(commandName == "EXIT") {
                break;
            } else if(commandName == "RUN" || commandName == "TRACE") {
                std::ifstream programFile;
                programFile.open(tokens.at(1));

                if (programFile.fail()) {
                    throw std::string("ERROR: File was not opened!");
                }

                runProgram((commandName == "TRACE"), &programFile);

            } else if(commandName == "INTERPRET") {
                std::stringstream programStream = takeProgramInput();
                runProgram(false, &programStream);

            } else {
                std::cout << "UNRECOGNIZED COMMAND" << std::endl;
            }

        } else {
            std::cout << "UNRECOGNIZED COMMAND" << std::endl;
        }
    }
}

std::stringstream Interpreter::takeProgramInput() {
    std::cout << "READY. Enter Bumpkin code line by line, finish with a . character" << std::endl;
    std::stringstream resultStream;
    std::string line;

    while(std::getline(std::cin, line)) {
        resultStream << line << "\n";

        if(line == ".") {
            break;
        }
    }

    return resultStream;
}


void Interpreter::runProgram(bool trace, std::istream* programStream) {
    Parser p;
    ProgramState state = p.getProgramState(programStream);

    while(!state.atProgramEnd()) {
        Statement* statement = state.getCurrentStatement();

        try {
            if(trace) {
                std::cout << *statement << std::endl;
            }
            statement->execute(state);
        } catch (BumpkinException& e) {
            std::cout << e.getMessage() << std::endl;
        }
    }
}