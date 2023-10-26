#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>
int main() {
  double stat1{0};
  double stat2{0};
  double tmp{0.};
  // Assume that numbers was a list of numbers passed in by the user, e.g. from
  // a program like the one in exercise 2
  std::vector<int> numbers{1, 2, 3, 4, 5, 6};
  for (std::size_t i{0}; i < numbers.size(); ++i) {
    auto number{numbers[i]};
    if (number % 2 == 0) {
      std::cout << number << ",";
    }
  }
  std::cout << "\n";
  if (numbers.size() == 0) {
    std::cout << "Numbers must have at least one entry!\n";
  }
  for (std::size_t j{0}; j < numbers.size(); ++j) {
    auto number{numbers[j]};
    stat1 += number;
  }
  stat1 /= numbers.size();
  for (std::size_t k{0}; k < numbers.size(); ++k) {
    auto number{numbers[k]};
    tmp += number * number;
  }
  stat2 = tmp / numbers.size() - stat1 * stat1;

  std::cout << stat1 << " (" << std::sqrt(stat2) << ")\n";
}