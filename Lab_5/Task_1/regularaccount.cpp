#include "regularaccount.h"

#include <iostream>

RegularAccount::RegularAccount(int number, const std::string &owner, long int balance, long int minimumAllowedBalance) : BankAccount(number, owner, balance)
{
    setMinimumAllowedBalance(minimumAllowedBalance);
}

RegularAccount& RegularAccount::operator+(const BankAccount &other)
{
    deposit(other.getBalance());
    return *this;
}

RegularAccount& RegularAccount::operator-(const BankAccount &other)
{
    withdraw(other.getBalance());
    return *this;
}

RegularAccount& RegularAccount::operator+=(double amount)
{
    deposit(amount);
    return *this;
}

RegularAccount& RegularAccount::operator-=(double amount)
{
    withdraw(amount);
    return *this;
}

long int RegularAccount::getMinimumAllowedBalance() const
{
    return minimumAllowedBalance;
}

void RegularAccount::setMinimumAllowedBalance(long int newMinimumAllowedBalance)
{
    if (newMinimumAllowedBalance < 0) {
        std::cout << "The minimum allowed balance cannot be less than zero." << std::endl;
        return;
    }

    minimumAllowedBalance = newMinimumAllowedBalance;
}

void RegularAccount::withdraw(double amount) {
    if (amount > balance) {
        std::cout << "There are not enough money in your account." << std::endl;
        return;
    }

    if (balance - amount < minimumAllowedBalance) {
        std::cout << "Balance cannot be less than the minimum allowed balance." << std::endl;
        return;
    }

    balance -= amount;
}

void RegularAccount::deposit(double amount) {
    if (amount <= 0) {
        std::cout << "The deposit amount cannot be less than or equal to zero." << std::endl;
        return;
    }

    balance += amount;
}

double RegularAccount::calculateInterest() const {
    return 0.0;
}
