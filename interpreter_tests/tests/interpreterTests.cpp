//
// Created by Daniel Shih on 11/25/17.
//

#include <Users/danielshih/CLionProjects/BumpkinInterpreter/interpreter/ProgramState.hpp>
#include <Users/danielshih/CLionProjects/BumpkinInterpreter/interpreter/LetStatement.hpp>
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