#include <gtest/gtest.h>
#include "comparison_operator.hpp"

TEST(ComparisonOperatorTest, Equal)
{
    EXPECT_EQ(comparison_equal(0, 0), true);
    EXPECT_EQ(comparison_equal(5, 5), true);
    EXPECT_EQ(comparison_equal(-40, -40), true);
}

TEST(ComparisonOperatorTest, NotEqual)
{
    EXPECT_EQ(comparison_equal(0, 1), false);
    EXPECT_EQ(comparison_equal(5, 6), false);
    EXPECT_EQ(comparison_equal(-40, -39), false);
}