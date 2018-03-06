#ifndef BUMPKININTERPRETER_STATEMENT_HPP
#define BUMPKININTERPRETER_STATEMENT_HPP

#include <string>
class ProgramState;

class Statement
{

public:
    Statement(unsigned int lineNumber, std::string statementText);
    virtual void execute(ProgramState& state) const;
    virtual ~Statement() = default;

    friend std::ostream& operator << (std::ostream& out, const Statement& statement);


private:
    unsigned int lineNumber;
    std::string statementText;

};
#endif //BUMPKININTERPRETER_STATEMENT_HPP
