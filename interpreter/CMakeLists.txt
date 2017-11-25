project(interpreter)

set(HEADER_FILES
        Interpreter.hpp
        LetStatement.hpp
        Parser.hpp
        PrintStatement.hpp
        ProgramState.hpp
        Statement.hpp
        Type.hpp)
set(SOURCE_FILES
        Interpreter.cpp
        LetStatement.cpp
        Parser.cpp
        PrintStatement.cpp
        ProgramState.cpp
        Statement.cpp)

add_library(interpreter STATIC ${SOURCE_FILES} ${HEADER_FILES})