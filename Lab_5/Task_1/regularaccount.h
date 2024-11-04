#ifndef REGULARACCOUNT_H
#define REGULARACCOUNT_H

#include "bankaccount.h"

class RegularAccount : public BankAccount
{
public:
    RegularAccount(int number, const std::string &owner, long int balance, long int minimumAllowedBalance);
    virtual RegularAccount& operator+(const BankAccount& other) override;
    virtual RegularAccount& operator-(const BankAccount& other) override;
    virtual RegularAccount& operator+=(double amount) override;
    virtual RegularAccount& operator-=(double amount) override;

    long int getMinimumAllowedBalance() const;
    void setMinimumAllowedBalance(long int newMinimumAllowedBalance);

    void withdraw(double amount) override;
    void deposit(double amount) override;
    double calculateInterest() const override;

private:
    long int minimumAllowedBalance;

};

#endif // REGULARACCOUNT_H
