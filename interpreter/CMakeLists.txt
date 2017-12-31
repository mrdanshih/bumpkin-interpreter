project(interpreter)

set(HEADER_FILES
        Interpreter.hpp
        control_statements/LetStatement.hpp
        Parser.hpp
        control_statements/PrintStatement.hpp
        ProgramState.hpp
        Statement.hpp
        control_statements/EndStatement.hpp
        arithmetic_statements/AddStatement.hpp
        arithmetic_statements/SubStatement.hpp
        enumerations/VariableType.hpp arithmetic_statements/MultStatement.cpp arithmetic_statements/MultStatement.hpp arithmetic_statements/DivStatement.cpp arithmetic_statements/DivStatement.hpp BumpkinException.cpp BumpkinException.hpp control_statements/GoToStatement.cpp control_statements/GoToStatement.hpp control_statements/IfStatement.cpp control_statements/IfStatement.hpp enumerations/LineLabelType.hpp enumerations/RelationalOperator.hpp ComparisonValue.cpp ComparisonValue.hpp control_statements/GoSubStatement.cpp control_statements/GoSubStatement.hpp control_statements/ReturnStatement.cpp control_statements/ReturnStatement.hpp)
set(SOURCE_FILES
        Interpreter.cpp
        control_statements/LetStatement.cpp
        Parser.cpp
        control_statements/PrintStatement.cpp
        ProgramState.cpp
        control_statements/EndStatement.cpp
        arithmetic_statements/AddStatement.cpp
        arithmetic_statements/SubStatement.cpp
        Statement.cpp arithmetic_statements/MultStatement.cpp arithmetic_statements/MultStatement.hpp arithmetic_statements/DivStatement.cpp arithmetic_statements/DivStatement.hpp BumpkinException.cpp BumpkinException.hpp control_statements/GoToStatement.cpp control_statements/GoToStatement.hpp control_statements/IfStatement.cpp control_statements/IfStatement.hpp ComparisonValue.cpp ComparisonValue.hpp control_statements/GoSubStatement.cpp control_statements/GoSubStatement.hpp control_statements/ReturnStatement.cpp control_statements/ReturnStatement.hpp)

add_library(interpreter STATIC ${SOURCE_FILES} ${HEADER_FILES})