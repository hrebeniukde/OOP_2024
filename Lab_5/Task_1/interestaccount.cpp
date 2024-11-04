#include "interestaccount.h"

#include <iostream>

InterestAccount::InterestAccount(int number, const std::string &owner, long int balance, int interestRate) : BankAccount(number, owner, balance)
{
    setInterestRate(interestRate);
}

InterestAccount& InterestAccount::operator+(const BankAccount &other)
{
    deposit(other.getBalance());
    return *this;
}

InterestAccount& InterestAccount::operator-(const BankAccount &other)
{
    withdraw(other.getBalance());
    return *this;
}

InterestAccount& InterestAccount::operator+=(double amount)
{
    deposit(amount);
    return *this;
}

InterestAccount& InterestAccount::operator-=(double amount)
{
    withdraw(amount);
    return *this;
}

int InterestAccount::getInterestRate() const
{
    return interestRate;
}

void InterestAccount::setInterestRate(int newInterestRate)
{
    if (newInterestRate <= 0) {
        std::cout << "The interest rate cannot be equal to or less than zero." << std::endl;
        return;
    }

    interestRate = newInterestRate;
}

void InterestAccount::withdraw(double amount) {
    if (amount > balance) {
        std::cout << "There are not enough money in your account." << std::endl;
        return;
    }

    balance -= amount;
}

void InterestAccount::deposit(double amount) {
    if (amount <= 0) {
        std::cout << "The deposit amount cannot be less than or equal to zero." << std::endl;
        return;
    }

    balance += amount;
    balance += calculateInterest();
}

double InterestAccount::calculateInterest() const {
    return balance * interestRate / 100;
}
