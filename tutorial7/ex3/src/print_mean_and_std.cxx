#include "print_mean_and_std.h"

void print_mean_and_std(const std::vector<int> numbers)
{
    const auto size{numbers.size()};
    const double mean{std::accumulate(numbers.begin(), numbers.end(), 0.)/size};
    // This for some reason gives an incorrect answer
    // const double squared_sum = static_cast<double>(std::inner_product(numbers.begin(), numbers.end(), numbers.begin(), 1));
    double squared_sum {0};
    for (auto number : numbers) {
        squared_sum += static_cast<double>(number * number);
    }
    const double variance{squared_sum / size - mean * mean};
    std::cout << mean << " (" << std::sqrt(variance) << ")\n";
    //std::cout << "updating" << "\n";
}
