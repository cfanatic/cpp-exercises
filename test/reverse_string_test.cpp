#include <gtest/gtest.h>
#include "reverse_string.hpp"

TEST(reverse_string_test, input_string)
{
    EXPECT_EQ(reverse_string("hello"), "olleh");
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}