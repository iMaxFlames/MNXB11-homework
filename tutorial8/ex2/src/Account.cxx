#include "Account.h"

namespace SEB
{
    Account::Account(double balance) 
    {
        if (!Account::is_valid_balance(balance))
        {
            throw std::invalid_argument("Invalid balance");
        }
        _balance = balance;
    }

    bool Account::is_valid_balance(double balance) const
    {
        return balance >= 0.0;
    }

    void Account::deposite(double amount)
    {
        if (!Account::is_valid_balance(amount))
        {
            throw std::invalid_argument("Invalid amount");
        }
        _balance += amount;
    }

    void Account::withdraw(double amount) {
        if (!Account::is_valid_balance(amount))
        {
            throw std::invalid_argument("Invalid amount");
        }
        double test {_balance - amount};
        if (!Account::is_valid_balance(test))
        {
            throw std::invalid_argument("Cannot withdraw amount");
        }
        _balance = test;
    }
} // namespace SEB
