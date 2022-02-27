#include <gtest/gtest.h>
#include "reverse_string.hpp"

TEST(reverse_string_test, input_string)
{
    EXPECT_EQ(reverse_string("hello"), "olleh");
}