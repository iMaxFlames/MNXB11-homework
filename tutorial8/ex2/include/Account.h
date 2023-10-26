#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <stdexcept>
namespace SEB
{
    class Account
    {
    private:
        double _balance;
        bool is_valid_balance(double balance) const;

    public:
        double get_balance() const { return _balance; }
        Account() = default;
        explicit Account(double balance);
        void deposite(double amount);
        void withdraw(double amount);
    };
}
#endif // ACCOUNT_H