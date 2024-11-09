#include <iostream>
#include <string>
#include <vector>


class Student
{
protected:
    std::string name;
    int age;
    double rating;
public:
    Student(std::string name, int age, double rating) : 
        name(name), age(age), rating(rating) {};
    
    void DisplayInfo() const {
        std::cout << "Имя: " << name << " Возраст: " << age << " Средняя оценка: " << rating << std::endl;
    }

    std::string GetName() const {
        return name;
    }
};

class ManagerStudent
{
private:
    std::vector<Student> students;
public:

    void AddStudent(const Student& student) {
        students.push_back(student);
    }

    void RemoveStudent(const std::string &name){
        for (auto it = students.begin(); it != students.end(); ++it) {
            if(it->GetName() == name){
                students.erase(it);
                std::cout << "Данный студент удалён из списка" << std::endl;
                break;
            }
        }
    }

    void StudentInfo() const {
        for(const auto& student : students){
            student.DisplayInfo();
        }
    }
};


int main() {
    ManagerStudent mang;
    mang.AddStudent(Student("Alice", 19, 4.5));
    mang.AddStudent(Student("Bob", 23, 3.35));
    mang.AddStudent(Student("Josh", 21, 2.1));

    mang.StudentInfo();

    mang.RemoveStudent("Bob");

    mang.StudentInfo();

    return 0;
}