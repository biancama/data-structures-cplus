//
// Created by Massimo Biancalani on 27/04/16.
//

#include "gtest/gtest.h"
#include "Stack.hpp"
TEST(stack_check, stack01) {
    structure::Stack<int> s;

    ASSERT_TRUE(s.empty());

    s.push(7);
    s.push(13);
    ASSERT_FALSE(s.empty());

}

TEST(stack_check, stack02) {
    structure::Stack<int> s(2);

    ASSERT_TRUE(s.empty());

    s.push(7);
    ASSERT_FALSE(s.empty());
    s.push(13);
    s.push(15);
    ASSERT_EQ(15, s.top());
    ASSERT_EQ(3, s.size());
    s.pop();
    ASSERT_EQ(13, s.top());
    s.pop();
    ASSERT_EQ(7, s.top());
    s.pop();
    ASSERT_TRUE(s.empty());
    ASSERT_THROW(s.top(), structure::StackEmpty);
}

