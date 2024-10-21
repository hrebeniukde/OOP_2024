#ifndef INTERESTACCOUNT_H
#define INTERESTACCOUNT_H

#include "bankaccount.h"

class InterestAccount : public BankAccount
{
public:
    InterestAccount(int number, const std::string &owner, long int balance, int interestRate);

    int getInterestRate() const;
    void setInterestRate(int newInterestRate);

    void withdraw(double amount) override;
    void deposit(double amount) override;
    double calculateInterest() const override;

private:
    int interestRate;

};

#endif // INTERESTACCOUNT_H
