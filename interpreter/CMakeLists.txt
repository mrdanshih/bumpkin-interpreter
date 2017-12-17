project(interpreter)

set(HEADER_FILES
        Interpreter.hpp
        LetStatement.hpp
        Parser.hpp
        PrintStatement.hpp
        ProgramState.hpp
        Statement.hpp
        EndStatement.hpp
        AddStatement.hpp
        SubStatement.hpp
        Type.hpp)
set(SOURCE_FILES
        Interpreter.cpp
        LetStatement.cpp
        Parser.cpp
        PrintStatement.cpp
        ProgramState.cpp
        EndStatement.cpp
        AddStatement.cpp
        SubStatement.cpp
        Statement.cpp)

add_library(interpreter STATIC ${SOURCE_FILES} ${HEADER_FILES})