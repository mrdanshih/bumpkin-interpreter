//
// Created by Daniel Shih on 11/25/17.
//

#include <Users/danielshih/CLionProjects/BumpkinInterpreter/interpreter/ProgramState.hpp>
#include <Users/danielshih/CLionProjects/BumpkinInterpreter/interpreter/LetStatement.hpp>
#include <Users/danielshih/CLionProjects/BumpkinInterpreter/interpreter/arithmetic/AddStatement.hpp>
#include <Users/danielshih/CLionProjects/BumpkinInterpreter/interpreter/arithmetic/SubStatement.hpp>
#include <Users/danielshih/CLionProjects/BumpkinInterpreter/interpreter/arithmetic/MultStatement.hpp>
#include <Users/danielshih/CLionProjects/BumpkinInterpreter/interpreter/arithmetic/DivStatement.hpp>
#include <Users/danielshih/CLionProjects/BumpkinInterpreter/interpreter/BumpkinException.hpp>
#include <Users/danielshih/CLionProjects/BumpkinInterpreter/interpreter/Parser.hpp>
#include "gtest/gtest.h"

TEST(basic_tests, test_let) {
    ProgramState state;
    LetStatement letA{"A", 1};
    LetStatement letB_equalA{"B", "A"};
    letA.execute(state);
    letB_equalA.execute(state);

    ASSERT_EQ(state.getVariableValue("A"), 1);
    ASSERT_EQ(state.getVariableValue("B"), 1);

    LetStatement changeA{"A", -3};
    changeA.execute(state);
    ASSERT_EQ(state.getVariableValue("A"),-3);
}


TEST(basic_tests, test_addition) {
    ProgramState state;
    state.setVariableValue("A", 0);
    AddStatement firstAdd("A", 10);
    firstAdd.execute(state);

    ASSERT_EQ(state.getVariableValue("A"), 10);

    state.setVariableValue("B", -40);

    AddStatement secondAdd("B", "A");
    secondAdd.execute(state);
    ASSERT_EQ(state.getVariableValue("B"), -30);
}

TEST(basic_tests, test_subtraction) {
    ProgramState state;
    state.setVariableValue("A", 50);
    SubStatement firstSub("A", 40);
    firstSub.execute(state);

    ASSERT_EQ(state.getVariableValue("A"), 10);

    state.setVariableValue("B", -10);
    SubStatement secondSub("B", "A");
    secondSub.execute(state);
    ASSERT_EQ(state.getVariableValue("B"), -20);
}

TEST(basic_tests, test_multiplication) {
    ProgramState state;
    state.setVariableValue("A", 50);
    MultStatement firstMult("A", 0);
    firstMult.execute(state);

    ASSERT_EQ(state.getVariableValue("A"), 0);

    state.setVariableValue("C", -16);
    state.setVariableValue("B", 9);
    MultStatement secondMult("B", "C");
    secondMult.execute(state);
    ASSERT_EQ(state.getVariableValue("B"), -144);
    ASSERT_EQ(state.getVariableValue("C"), -16);
}

TEST(basic_tests, test_division) {
    ProgramState state;
    state.setVariableValue("A", 50);
    DivStatement firstDiv("A", 5);
    firstDiv.execute(state);

    ASSERT_EQ(state.getVariableValue("A"), 10);

    state.setVariableValue("A", 10);
    state.setVariableValue("B", 6);
    DivStatement secondDiv("A", "B");
    secondDiv.execute(state);
    ASSERT_EQ(state.getVariableValue("A"), 1);
    DivStatement thirdDiv("A", 0);
    ASSERT_THROW(thirdDiv.execute(state), BumpkinException);
}

TEST(basic_tests, test_labeling) {
    Parser test;
    std::string labelTest = "LABEL: LET X 5\nBLAH: LET Y 10";
    std::istringstream iss(labelTest);
    ProgramState s = test.getProgramState(&iss);
    ASSERT_EQ(s.getLineNumber("LABEL"), 1);
    ASSERT_EQ(s.getLineNumber("BLAH"), 2);
}

TEST(basic_tests, test_goto) {
    Parser test;
    std::string goToTest = "LET A 1\nGOTO 4\nLET A 2\nLET A 10";
    std::istringstream iss(goToTest);
    ProgramState s = test.getProgramState(&iss);

    s.getCurrentStatement()->execute(s);
    s.getCurrentStatement()->execute(s);
    s.getCurrentStatement()->execute(s);

    ASSERT_EQ(s.getVariableValue("A"), 10);
}