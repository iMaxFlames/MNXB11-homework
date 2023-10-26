#include "Circle.h"
#include "GeometryIO.h"
#include "Rectangle.h"
#include "parse_csv.h"
#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    const std::string csv_file{"rectangle_dimensions.csv"};
    auto rectangles{parse_rectangles(csv_file)};
    std::vector<double> vector_of_area{};

    for (auto rectangle : rectangles)
    {
        double a{rectangle.area()};
        vector_of_area.push_back(a);
    }

    const auto size{vector_of_area.size()};
    const double mean{std::accumulate(vector_of_area.begin(), vector_of_area.end(), 0.) / size};
    // const double squared_sum = std::inner_product(vector_of_area.begin(), vector_of_area.end(), vector_of_area.begin(), 1);

    // The code below does the same thing as the commented
    // code but it does a better job.
    double squared_sum{0};
    for (auto number : vector_of_area)
    {
        squared_sum += static_cast<double>(number * number);
    }

    const double variance{squared_sum / size - mean * mean};
    std::cout << mean << " (" << std::sqrt(variance) << ")\n";

    return 0;
}