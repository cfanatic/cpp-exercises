#include <gtest/gtest.h>
#include "reverse_string.hpp"

TEST(ReverseStringTest, String)
{
    EXPECT_EQ(reverse_string("hello"), "olleh");
}