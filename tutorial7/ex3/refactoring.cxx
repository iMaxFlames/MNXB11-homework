#include "print_even.h"
#include "print_mean_and_std.h"
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

int main()
{
    // Assume that numbers was a list of numbers passed in by the user, e.g. from
    // a program like the one in exercise 2

    const std::vector<int> numbers{1, 2, 3, 4, 5, 6};
    print_even(numbers);
    print_mean_and_std(numbers);
}