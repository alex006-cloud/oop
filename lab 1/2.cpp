#include <iostream>

class Calculator
{
private:
    double x, y;
public:
    Calculator(){
        double x = 0.0; 
        double y = 0.0;
    };

    double plus(double x, double y){
        double sum = x + y;
        std::cout << "Сумма этих двух чисел: " << sum << std::endl;
    };

    double minus(double x, double y){
        double inversion_sum = x - y;
        std::cout << "Вычитние этих двух чисел: " << inversion_sum << std::endl;
    };

    double division(double x, double y){
        if (x == 0 or y == 0) {
            std::cout << "На ноль делить нельзя" << std::endl;
        }else{
            double divis = (x / y);
            std::cout << "Деление этих двух чисел: " << divis << std::endl;
        }
        
    };

    double multiplication(double x, double y){
        double multi = x * y;
        std::cout << "Произведение этих двух чисел: " << multi << std::endl;
    };
};

int main() {
    Calculator cal;

    cal.plus(1.23, 4.53);

    cal.minus(4.53, 1.23);

    cal.division(4.5, 0);
    cal.division(53.95, 8.3);

    cal.multiplication(6.5, 8.3);
}
