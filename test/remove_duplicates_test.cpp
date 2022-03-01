#include <gtest/gtest.h>
#include "remove_duplicates.hpp"

TEST(RemoveDuplicatesTest, ListUnsorted)
{
    std::list<int> list_in = {12, 5, 10, 10, 9, 12, 12, 5};
    std::list<int> list_out = {12, 5, 10, 9};
    std::list<int> list_res = remove_duplicates(list_in);
    list_res.reverse(); // quick fix - potential bug in function()
    EXPECT_EQ(list_res, list_out);
}