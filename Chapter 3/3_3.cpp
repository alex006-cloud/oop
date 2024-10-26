#include <iostream>
#include <string>

// Класс Student
class Student {
public:
    std::string name;
    int grade;

    Student(const std::string &name) : name(name), grade(0) {}

    virtual void displayInfo() const {
        std::cout << "Student: " << name << ", Grade: " << grade << std::endl;
    }

    void setGrade(int grade) {
        this->grade = grade;
    }
};

// Класс InternationalStudent, наследующий от Student
class InternationalStudent : public Student {
public:
    std::string country;

    InternationalStudent(const std::string &name, const std::string &country)
        : Student(name), country(country) {}

    void displayInfo() const override {
        std::cout << "International Student: " << name << ", Country: " << country << ", Grade: " << grade << std::endl;
    }
};

// Класс Teacher
class Teacher {
private:
    std::string name;
    Student &student;

public:
    Teacher(const std::string &name, Student &student) : name(name), student(student) {}

    void evaluateStudent(int grade) {
        student.setGrade(grade);
        std::cout << name << " evaluated " << student.name << " with a grade of " << grade << std::endl;
    }

    void displayInfo() const {
        std::cout << "Teacher: " << name << std::endl;
        student.displayInfo();
    }
};

int main() {
    Student student1("Alice");
    InternationalStudent student2("Bob", "Canada");

    Teacher teacher1("Mr. Smith", student1);
    Teacher teacher2("Ms. Johnson", student2);

    teacher1.evaluateStudent(85);
    teacher2.evaluateStudent(90);

    teacher1.displayInfo();
    teacher2.displayInfo();

    return 0;
}
