project(interpreter)

set(HEADER_FILES
        Interpreter.hpp
        LetStatement.hpp
        Parser.hpp
        PrintStatement.hpp
        ProgramState.hpp
        Statement.hpp
        EndStatement.hpp
        arithmetic/AddStatement.hpp
        arithmetic/SubStatement.hpp
        enumerations/VariableType.hpp arithmetic/MultStatement.cpp arithmetic/MultStatement.hpp arithmetic/DivStatement.cpp arithmetic/DivStatement.hpp BumpkinException.cpp BumpkinException.hpp GoToStatement.cpp GoToStatement.hpp IfStatement.cpp IfStatement.hpp enumerations/LineLabelType.hpp enumerations/RelationalOperator.hpp ComparisonValue.cpp ComparisonValue.hpp)
set(SOURCE_FILES
        Interpreter.cpp
        LetStatement.cpp
        Parser.cpp
        PrintStatement.cpp
        ProgramState.cpp
        EndStatement.cpp
        arithmetic/AddStatement.cpp
        arithmetic/SubStatement.cpp
        Statement.cpp arithmetic/MultStatement.cpp arithmetic/MultStatement.hpp arithmetic/DivStatement.cpp arithmetic/DivStatement.hpp BumpkinException.cpp BumpkinException.hpp GoToStatement.cpp GoToStatement.hpp IfStatement.cpp IfStatement.hpp ComparisonValue.cpp ComparisonValue.hpp)

add_library(interpreter STATIC ${SOURCE_FILES} ${HEADER_FILES})