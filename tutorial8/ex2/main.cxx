#include "Account.h"
#include <iostream>
#include <stdexcept>

int main()
{
    using namespace SEB;
    
    try
    {
        Account valid_account{1000.0};

        // Produced error: invalid balance
        // Account in_valid_account{-500.0};

        valid_account.withdraw(1500);

        std::cout << "Current balance is: " << valid_account.get_balance() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}