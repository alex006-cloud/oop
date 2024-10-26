#include <iostream>

class Employee {
public:
    virtual void work() const {
        std::cout << "Employee is working" << std::endl;
    }
};

class Manager : virtual public Employee {
public:
    void delegate() const {
        std::cout << "Manager is delegating" << std::endl;
    }
};

class Developer : virtual public Employee {
public:
    void code() const {
        std::cout << "Developer is coding" << std::endl;
    }
};

class TechManager : public Manager, public Developer {
public:
    void work() const override {
        std::cout << "TechManager is working" << std::endl;
    }
};

int main() {
    TechManager tm;
    tm.work();
    tm.delegate();
    tm.code();
    return 0;
}
