#include "bankaccount.h"

#include <iostream>

BankAccount::BankAccount(int number, const std::string &owner, long int balance)
{
    setNumber(number);
    setOwner(owner);
    setBalance(balance);
}

int BankAccount::getNumber() const
{
    return number;
}

void BankAccount::setNumber(int newNumber)
{
    if (newNumber <= 0) {
        std::cout << "The account number cannot be less than or equal to zero." << std::endl;
        return;
    }

    number = newNumber;
}

std::string BankAccount::getOwner() const
{
    return owner;
}

void BankAccount::setOwner(const std::string &newOwner)
{
    if (newOwner.empty()) {
        std::cout << "You have not entered the name of the account holder." << std::endl;
        return;
    }

    owner = newOwner;
}

long int BankAccount::getBalance() const
{
    return balance;
}

void BankAccount::setBalance(long int newBalance)
{
    balance = newBalance;
}
