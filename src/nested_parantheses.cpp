// ==========================================================================================
// You are given a string that contains left and right paranthesis characters.
// Write code to determine whether the paranthesis are correctly nested.
// For example, the strings "(())" and "()()" are correctly nested,
// but "(()()" and ")(" are not.
// ==========================================================================================

#include "nested_parantheses.hpp"

bool nested_parantheses(std::string str)
{
    signed int res = 0;
    for (auto chr : str)
    {
        if (chr == '(')
            res += 1;
        else if (chr == ')')
            res -= 1;
        if (res < 0)
            return false;
    }
    if (!res)
        return true;
    else
        return false;
}