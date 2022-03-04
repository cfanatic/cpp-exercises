#include <gtest/gtest.h>
#include "maximum_value.hpp"

TEST(CompareToMaxTest, ArrayEmpty)
{
    std::vector<int> input{};
    EXPECT_EQ(compare_to_max(input, 0), -1);
}

TEST(CompareToMaxTest, ArrayFilled)
{
    std::vector<int> input{3, 4, 1, 0, 9, 5, 2, 7, 6, 8};
    EXPECT_EQ(compare_to_max(input, 10), 9);
}

TEST(CompareToAllTest, ArrayEmpty)
{
    std::vector<int> input{};
    EXPECT_EQ(compare_to_all(input, 0), -1);
}

TEST(CompareToAllTest, ArrayFilled)
{
    std::vector<int> input{3, 8, 1, 0, 9, 5, 2, 7, 6, 4};
    EXPECT_EQ(compare_to_all(input, 10), 9);
}