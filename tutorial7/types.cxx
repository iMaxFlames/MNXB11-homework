#include <vector>
int main()
{
    int age = 20;
    bool is_adult = age > 18;
    std::vector<int> list_of_integers{1, 2, 3};
    // Casting or converting from one type to another *intentinoally*
    const int i{static_cast<int>(3.9999999999)};
    // i = 4; // gives compiler error
}