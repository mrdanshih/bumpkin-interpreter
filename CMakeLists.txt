cmake_minimum_required(VERSION 3.6)

project(BumpkinInterpreter)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp)
add_executable(interpreter_run ${SOURCE_FILES})

add_subdirectory(interpreter)
add_subdirectory(interpreter_tests)

target_link_libraries(interpreter_run interpreter)