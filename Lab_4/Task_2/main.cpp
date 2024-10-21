#include <iostream>
#include <vector>

#include "bankaccount.h"
#include "regularaccount.h"
#include "interestaccount.h"

void showMenu() {
    std::cout << "\n1. Create a new regular account\n";
    std::cout << "2. Create a new interest account\n";
    std::cout << "3. Deposit to account\n";
    std::cout << "4. Withdraw from account\n";
    std::cout << "5. Switch account\n";
    std::cout << "6. Show balance\n";
    std::cout << "7. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    std::vector<BankAccount*> accounts;
    int currentAccount = -1;

    while (true) {
        showMenu();
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            int number;
            std::string owner;
            long int balance, minimumBalance;
            std::cout << "Enter account number: ";
            std::cin >> number;
            std::cout << "Enter owner name: ";
            std::cin >> owner;
            std::cout << "Enter starting balance: ";
            std::cin >> balance;
            std::cout << "Enter minimum allowed balance: ";
            std::cin >> minimumBalance;

            accounts.push_back(new RegularAccount(number, owner, balance, minimumBalance));
            currentAccount = accounts.size() - 1;
        } else if (choice == 2) {
            int number;
            std::string owner;
            long int balance;
            int interestRate;
            std::cout << "Enter account number: ";
            std::cin >> number;
            std::cout << "Enter owner name: ";
            std::cin >> owner;
            std::cout << "Enter starting balance: ";
            std::cin >> balance;
            std::cout << "Enter interest rate: ";
            std::cin >> interestRate;

            accounts.push_back(new InterestAccount(number, owner, balance, interestRate));
            currentAccount = accounts.size() - 1;
        } else if (choice == 3) {
            if (currentAccount < 0) {
                std::cout << "No account selected.\n";
                continue;
            }
            double amount;
            std::cout << "Enter amount to deposit: ";
            std::cin >> amount;
            accounts[currentAccount]->deposit(amount);
            std::cout << "Deposit successful.\n";
        } else if (choice == 4) {
            if (currentAccount < 0) {
                std::cout << "No account selected.\n";
                continue;
            }
            double amount;
            std::cout << "Enter amount to withdraw: ";
            std::cin >> amount;
            accounts[currentAccount]->withdraw(amount);
            std::cout << "Withdrawal attempt completed.\n";
        } else if (choice == 5) {
            int accountIndex;
            std::cout << "Enter account index to switch (0 - " << accounts.size() - 1 << "): ";
            std::cin >> accountIndex;
            if (accountIndex >= 0 && accountIndex < accounts.size()) {
                currentAccount = accountIndex;
                std::cout << "Switched to account " << currentAccount << ".\n";
            } else {
                std::cout << "Invalid account index.\n";
            }
        } else if (choice == 6) {
            if (currentAccount < 0) {
                std::cout << "No account selected.\n";
                continue;
            }

            std::cout << "Current balance: " << accounts[currentAccount]->getBalance() << "\n";
        } else if (choice == 7) {
            break;
        } else {
            std::cout << "Invalid choice.\n";
        }
    }

    for (BankAccount* account : accounts) {
        delete account;
    }

    return 0;
}
