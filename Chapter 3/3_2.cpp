#include <iostream>
#include <vector>
#include <string>

// Класс Student
class Student {
public:
    std::string name;

    Student(const std::string &name) : name(name) {}

    virtual void displayInfo() const {
        std::cout << "Student: " << name << std::endl;
    }
};

// Класс InternationalStudent, наследующий от Student
class InternationalStudent : public Student {
public:
    std::string country;

    InternationalStudent(const std::string &name, const std::string &country)
        : Student(name), country(country) {}

    void displayInfo() const override {
        std::cout << "International Student: " << name << ", Country: " << country << std::endl;
    }
};

// Класс Course
class Course {
private:
    std::vector<Student*> students;

public:
    void addStudent(Student* student) {
        students.push_back(student);
    }

    void displayStudents() const {
        for (const auto &student : students) {
            student->displayInfo();
        }
    }

    ~Course() {
        for (auto &student : students) {
            delete student;
        }
    }
};

int main() {
    Course course;

    Student* student1 = new Student("Alice");
    InternationalStudent* student2 = new InternationalStudent("Bob", "Canada");

    course.addStudent(student1);
    course.addStudent(student2);

    course.displayStudents();

    return 0;
}
