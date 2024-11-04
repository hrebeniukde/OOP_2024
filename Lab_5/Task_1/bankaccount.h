#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

class BankAccount
{
public:
    BankAccount(int number, const std::string &owner, long int balance);
    virtual BankAccount& operator+(const BankAccount& other) = 0;
    virtual BankAccount& operator-(const BankAccount& other) = 0;
    virtual BankAccount& operator+=(double amount) = 0;
    virtual BankAccount& operator-=(double amount) = 0;

    int getNumber() const;
    void setNumber(int newNumber);

    std::string getOwner() const;
    void setOwner(const std::string &newOwner);

    long int getBalance() const;
    void setBalance(long int newBalance);

    virtual void withdraw(double amount) = 0;
    virtual void deposit(double amount) = 0;
    virtual double calculateInterest() const = 0;

protected:
    int number;
    std::string owner;
    long int balance;

};

#endif // BANKACCOUNT_H
