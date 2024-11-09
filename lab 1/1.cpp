#include <iostream>

class Point
{
private:
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {};

    void wolk() {
        std::cout << "Точка была перемещенна на заданное растояния по x = " << x << ", y = " << y << "." << std::endl; 
    };
};

int main () {
    Point pt(12, 68);

    pt.wolk();

}