// ==========================================================================================
// Write a program that prints the numbers from 1 to 100.
// If a number is divisible by 3, print "Fizz" instead of the number.
// If a number is divisible by 5, print "Buzz" instead of the number.
// And if a number is divisible by both 3 and 5, print "FizzBuzz" instead of the number.
// ==========================================================================================

#include "fizz_buzz.hpp"

void fizz_buzz(int num)
{
    for (int i = 1; i <= num; i++)
    {
        if (i % 3 == 0)
            std::cout << "Fizz" << std::endl;
        else if (i % 5 == 0)
            std::cout << "Buzz" << std::endl;
        else if (i % 3 == 0 && i % 5 == 0)
            std::cout << "FizzBuzz" << std::endl;
        else
            std::cout << i << std::endl;
    }
}