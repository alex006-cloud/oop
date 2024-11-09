3. Разработайте класс Student (Студент), содержащий поля для имени, возраста и
средней оценки студента. Разработайте класс StudentManager (Менеджер студентов),
который будет управлять массивом студентов, позволяя добавлять, удалять и выводить
информацию о студентах.
4. Разработайте класс Book (Книга), представляющий собой книгу с полями для
названия, автора и года выпуска. Напишите программу, которая создает массив книг,
сортирует его по году выпуска и выводит отсортированный список книг.
5. Разработайте класс BankAccount (Банковский счет), содержащий информацию
о банковском счете (номер счета, баланс). Реализуйте методы для внесения и снятия
средств, а также для метод для перевода средств между счетами.
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
        std::cout << "BankAccount(Account Number: " << account_number << ", Balance: " << balance << ")" << std::endl;
    }
};
