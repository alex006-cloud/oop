#include <iostream>
#include <vector>
#include <string>

// Базовый класс Animal
class Animal {
public:
    virtual void sound() const {
        std::cout << "Some generic animal sound" << std::endl;
    }

    virtual ~Animal() {} // Виртуальный деструктор для корректного удаления производных объектов
};

// Производный класс Dog
class Dog : public Animal {
public:
    void sound() const override {
        std::cout << "Woof!" << std::endl;
    }
};

// Производный класс Cat
class Cat : public Animal {
public:
    void sound() const override {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    // Создаем массив указателей на Animal
    std::vector<Animal*> animals;

    // Заполняем массив объектами Dog и Cat
    animals.push_back(new Dog());
    animals.push_back(new Cat());

    // Выводим звуки, используя полиморфизм
    for (const auto &animal : animals) {
        animal->sound();
    }

    // Очистка памяти
    for (auto &animal : animals) {
        delete animal;
    }

    return 0;
}
