#include "print_even.h"

void print_even(const std::vector<int> numbers)
{
    for (auto number : numbers)
    {
        if (number % 2 == 0)
        {
            std::cout << number << ",";
        }
    }
    std::cout << "\n";
    if (numbers.size() == 0)
    {
        std::cout << "Numbers must have at least one entry!\n";
    }
}