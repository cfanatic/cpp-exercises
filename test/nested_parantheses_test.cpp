#include <gtest/gtest.h>
#include "nested_parantheses.hpp"

TEST(NestedParanthesesTest, Valid)
{
    EXPECT_EQ(nested_parantheses("(())"), true);
    EXPECT_EQ(nested_parantheses("()()"), true);
    EXPECT_EQ(nested_parantheses("()"), true);
    EXPECT_EQ(nested_parantheses("(()())"), true);
    EXPECT_EQ(nested_parantheses("((())(()))"), true);
}

TEST(NestedParanthesesTest, Invalid)
{
    EXPECT_EQ(nested_parantheses("(()()"), false);
    EXPECT_EQ(nested_parantheses("()("), false);
    EXPECT_EQ(nested_parantheses("()))"), false);
    EXPECT_EQ(nested_parantheses(")("), false);
    EXPECT_EQ(nested_parantheses("("), false);
    EXPECT_EQ(nested_parantheses(")"), false);
    EXPECT_EQ(nested_parantheses("(((("), false);
}