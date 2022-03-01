// ==========================================================================================
// Given an unsorted list of integers, write a function that returns a new list
// with all duplicate values removed.
// ==========================================================================================

#include "remove_duplicates.hpp"

std::list<int> remove_duplicates(std::list<int> input)
{
    std::unordered_set<int> set;
    std::list<int> list;
    set = std::unordered_set<int>(input.begin(), input.end());
    list = std::list<int>(set.begin(), set.end());
    return list;
}