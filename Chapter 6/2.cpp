#include <iostream>

class Animal {
public:
    virtual void speak() const {
        std::cout << "Animal is speaking" << std::endl;
    }
};

class Mammal : virtual public Animal {
public:
    void walk() const {
        std::cout << "Mammal is walking" << std::endl;
    }
};

class Bird : virtual public Animal {
public:
    void fly() const {
        std::cout << "Bird is flying" << std::endl;
    }
};

class Bat : public Mammal, public Bird {
public:
    void speak() const override {
        std::cout << "Bat is speaking" << std::endl;
    }
};

int main() {
    Bat bat;
    bat.speak();
    bat.walk();
    bat.fly();
    return 0;
}
