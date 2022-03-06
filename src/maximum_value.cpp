// ==========================================================================================
// Return the largest value in an array of n non-negative integers.
// ==========================================================================================

#include "maximum_value.hpp"

/*

Big-O Analysis
--------------

1. Figure out what the input is and what 'n' represents.
2. Express the number of operations the algorithm performs in terms of 'n'.
3. Eliminate all but the highest-order terms.
4. Remove all constant factors.

*/

int compare_to_max(std::vector<int> input, int n)
{
    int max = 0;

    if (n <= 0)
        return -1;

    for (const int &i : input)
    {
        if (i > max)
            max = i;
    }

    return max;
}

int compare_to_all(std::vector<int> input, int n)
{
    int i, j;
    bool max;

    if (n <= 0)
        return -1;

    for (i = 0; i < n; i++)
    {
        max = true;
        for (j = 0; j < n; j++)
        {
            if (input[j] > input[i])
            {
                max = false;
                break;
            }
        }
        if (max)
            break;
    }
    return input[i];
}