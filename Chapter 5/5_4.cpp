#include <iostream>
#include <vector>
#include <stdexcept>
#include <ctime>
#include <cstdlib>

template <typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;
    size_t rows;
    size_t cols;

public:
    // Конструктор для создания матрицы заданного размера
    Matrix(size_t rows, size_t cols) : rows(rows), cols(cols), data(rows, std::vector<T>(cols)) {}

    // Ввод матрицы
    void input() {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                data[i][j]  =  std::rand() % 11;
            }
        }
    }

    // Вывод матрицы
    void output() const {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    // Сложение матриц
    Matrix<T> operator+(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::runtime_error("Матрицы должны иметь одинаковый размер для сложения.");
        }

        Matrix<T> result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Вычитание матриц
    Matrix<T> operator-(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::runtime_error("Матрицы должны иметь одинаковый размер для вычитания.");
        }

        Matrix<T> result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    // Умножение матриц
    Matrix<T> operator*(const Matrix<T>& other) const {
        if (cols != other.rows) {
            throw std::runtime_error("Количество столбцов в первой матрице должно быть равно количеству строк во второй матрице для умножения.");
        }

        Matrix<T> result(rows, other.cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < other.cols; ++j) {
                result.data[i][j] = 0;
                for (size_t k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0)));

    Matrix<double> A(2, 3);
    Matrix<double> B(2, 3);

    A.input();
    B.input();

    std::cout << "Матрица A:" << std::endl;
    A.output();

    std::cout << "Матрица B:" << std::endl;
    B.output();

    Matrix<double> C = A + B;
    std::cout << "Матрица A + B:" << std::endl;
    C.output();

    C = A - B;
    std::cout << "Матрица A - B:" << std::endl;
    C.output();

    Matrix<double> D(3, 2);
    D.input();

    std::cout << "Матрица D:" << std::endl;
    D.output();

    Matrix<double> E = A * D;
    std::cout << "Матрица A * D:" << std::endl;
    E.output();

    return 0;
}
