#include <iostream>
#include <string>

int main()
{
    std::string name;
    std::cout << "What is your first name?" << std::endl;
    std::cin >> name;

    if (name == "Ayush")
    {
        std::cout << "Hello, " << name << "! Welcome back." << std::endl;
    }
    else
    {
        std::cout << "I'm sorry " << name << ", I don't believe I know you. You are welcome regardless!" << std::endl;
    }

    return 0;
}