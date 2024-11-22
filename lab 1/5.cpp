#include <iostream>
#include <string>

class BankAccount {
protected:
    std::string account_number;
    double balance;

public:
    BankAccount(std::string account_number, double balance = 0)
        : account_number(account_number), balance(balance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited " << amount << " to account " << account_number << std::endl;
        } else {
            std::cout << "Invalid deposit amount" << std::endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrew " << amount << " from account " << account_number << std::endl;
        } else {
            std::cout << "Insufficient funds or invalid amount" << std::endl;
        }
    }

    void transfer(BankAccount& other, double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            other.deposit(amount);
            std::cout << "Transferred " << amount << " from account " << account_number << " to account " << other.account_number << std::endl;
        } else {
            std::cout << "Insufficient funds or invalid amount" << std::endl;
        }
    }

    void display() const {
        std::cout << "Account Number: " << account_number << ", Balance: " << balance << std::endl;
    }
};

int main() {
    BankAccount account1("123456", 800);
    BankAccount account2("654321", 3000);

    account1.display();
    account2.display();

    account1.deposit(1200);
    account1.withdraw(1000);
    account1.transfer(account2, 1000);

    account1.display();
    account2.display();

    return 0;
}