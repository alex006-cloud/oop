#include <iostream>

class Date {
private:
    int day, month, year;

    bool isLeapYear(int year) const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    int daysInMonth(int month, int year) const {
        int days[] = {31, isLeapYear(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return days[month - 1];
    }

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // Перегрузка оператора +
    Date operator+(int daysToAdd) {
        int d = day;
        int m = month;
        int y = year;

        d += daysToAdd;
        while (d > daysInMonth(m, y)) {
            d -= daysInMonth(m, y);
            m++;
            if (m > 12) {
                m = 1;
                y++;
            }
        }

        return Date(d, m, y);
    }

    void display() const {
        std::cout << "Date: " << day << "/" << month << "/" << year << std::endl;
    }
};

int main() {
    Date date(31, 12, 2024);
    Date newDate = date + 10;
    newDate.display();
    return 0;
}
