#include <iostream>
#include <vector>

int main()
{
    int number_of_inputs{3};
    std::cout << "Please enter three integers in a row separated by whitespace (newline or space)" << std::endl;
    std::vector<int> user_integers;

    for (int counter{0}; counter < number_of_inputs; counter++)
    {
        int number{};
        std::cin >> number;
        user_integers.push_back(number);
    }

    std::cout << "You have entered the following numbers" << std::endl;
    int sum {};
    for (int number : user_integers)
    {
        std::cout << number << std::endl;
        sum += number;
    }

    std::cout << "The sum of the numbers is:" << std::endl;
    std::cout << sum << std::endl;

    return 0;
}