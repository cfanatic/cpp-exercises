// ==========================================================================================
// Write a function that determines whether two integers are equal without using
// any comparison operator.
// ==========================================================================================

#include "comparison_operator.hpp"

bool comparison_equal(int a, int b)
{
    return !(a ^ b);
}