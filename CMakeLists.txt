cmake_minimum_required(VERSION 3.6)

project(BumpkinInterpreter)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp LetStatement.hpp LetStatement.cpp
        ProgramState.hpp ProgramState.cpp
        Statement.hpp Statement.cpp)
add_executable(BumpkinInterpreter ${SOURCE_FILES})