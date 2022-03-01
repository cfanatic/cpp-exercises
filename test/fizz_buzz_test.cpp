#include <gtest/gtest.h>
#include "fizz_buzz.hpp"

TEST(FizzBuzzTest, NumTo15)
{
    ::testing::internal::CaptureStdout();
    fizz_buzz(15);
    std::string res = ::testing::internal::GetCapturedStdout().c_str();
    EXPECT_STREQ(res.c_str(), "1\n2\nFizz\n4\nBuzz\nFizz\n7\n8\nFizz\nBuzz\n11\nFizz\n13\n14\nFizzBuzz\n");
}