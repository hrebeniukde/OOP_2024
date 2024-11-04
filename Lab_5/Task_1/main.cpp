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
    std::cout << "7. Combine accounts using + operator\n";
    std::cout << "8. Subtract accounts using - operator\n";
    std::cout << "9. Add amount using += operator\n";
    std::cout << "10. Subtract amount using -= operator\n";
    std::cout << "11. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    std::vector<BankAccount*> accounts;
    int currentAccount = -1;

    while (true) {
        showMenu();
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: {
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
            break;
        }
        case 2: {
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
            break;
        }
        case 3: {
            if (currentAccount < 0) {
                std::cout << "No account selected.\n";
                break;
            }

            double amount;
            std::cout << "Enter amount to deposit: ";
            std::cin >> amount;
            accounts[currentAccount]->deposit(amount);
            std::cout << "Deposit successful.\n";
            break;
        }
        case 4: {
            if (currentAccount < 0) {
                std::cout << "No account selected.\n";
                break;
            }

            double amount;
            std::cout << "Enter amount to withdraw: ";
            std::cin >> amount;
            accounts[currentAccount]->withdraw(amount);
            std::cout << "Withdrawal attempt completed.\n";
            break;
        }
        case 5: {
            int accountIndex;
            std::cout << "Enter account index to switch (0 - " << accounts.size() - 1 << "): ";
            std::cin >> accountIndex;

            if (accountIndex >= 0 && accountIndex < accounts.size()) {
                currentAccount = accountIndex;
                std::cout << "Switched to account " << currentAccount << ".\n";
            } else {
                std::cout << "Invalid account index.\n";
            }
            break;
        }
        case 6: {
            if (currentAccount < 0) {
                std::cout << "No account selected.\n";
                break;
            }

            std::cout << "Current balance: " << accounts[currentAccount]->getBalance() << "\n";
            break;
        }
        case 7:
        case 8: {
            if (currentAccount < 0 || accounts.size() < 2) {
                std::cout << "Two accounts are required for this operation.\n";
                break;
            }

            int otherAccount;
            std::cout << "Enter index of another account: ";
            std::cin >> otherAccount;

            if (otherAccount >= 0 && otherAccount < accounts.size() && otherAccount != currentAccount) {
                if (choice == 7) {
                    *accounts[currentAccount] + *accounts[otherAccount];
                    std::cout << "Accounts combined.\n";
                } else {
                    *accounts[currentAccount] - *accounts[otherAccount];
                    std::cout << "Accounts subtracted.\n";
                }
            } else {
                std::cout << "Invalid account selection.\n";
            }
            break;
        }
        case 9: {
            if (currentAccount < 0) {
                std::cout << "No account selected.\n";
                break;
            }

            double amount;
            std::cout << "Enter amount to add: ";
            std::cin >> amount;
            *accounts[currentAccount] += amount;
            std::cout << "Amount added.\n";
            break;
        }
        case 10: {
            if (currentAccount < 0) {
                std::cout << "No account selected.\n";
                break;
            }

            double amount;
            std::cout << "Enter amount to subtract: ";
            std::cin >> amount;
            *accounts[currentAccount] -= amount;
            std::cout << "Amount subtracted.\n";
            break;
        }
        case 11:
            for (BankAccount* account : accounts) {
                delete account;
            }
            return 0;
        default:
            std::cout << "Invalid choice.\n";
        }
    }
}
