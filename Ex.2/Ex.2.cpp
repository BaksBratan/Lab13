#include <iostream>
#include <vector>
#include <limits>

// Функція для виведення матриці на екран
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int element : row) {
            std::cout << element << "\t";
        }
        std::cout << std::endl;
    }
}

int main() {
    // Розмірність матриці
    const int numRows = 3; // Змініть розмірність матриці за потребою
    const int numCols = 4;

    // Заповнення матриці випадковими числами
    std::vector<std::vector<int>> matrix(numRows, std::vector<int>(numCols, 0));
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            matrix[i][j] = rand() % 100; // Генерація чисел в діапазоні від 0 до 99
        }
    }

    // Виведення початкової матриці
    std::cout << "Initial matrix:" << std::endl;
    printMatrix(matrix);
    std::cout << std::endl;

    // Знаходження та виведення максимального елемента для кожного рядка
    for (int i = 0; i < numRows; ++i) {
        int maxElement = std::numeric_limits<int>::min();

        for (int j = 0; j < numCols; ++j) {
            if (matrix[i][j] > maxElement) {
                maxElement = matrix[i][j];
            }
        }

        std::cout << "The maximum element in a row " << i + 1 << ": " << maxElement << std::endl;
    }

    return 0;
}