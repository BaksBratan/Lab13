#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

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
    // Ініціалізація генератора випадкових чисел
    std::srand(std::time(0));

    // Розмірність матриці
    const int n = 5; // Змініть розмірність матриці за потребою

    // Заповнення матриці випадковими числами
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = std::rand() % 201 - 100; // Генерація чисел в діапазоні від -100 до 100
        }
    }

    // Виведення початкової матриці
    std::cout << "Initial matrix:" << std::endl;
    printMatrix(matrix);
    std::cout << std::endl;

    // Обчислення сум та розміщення на головній діагоналі
    for (int i = 0; i < n; ++i) {
        int sum = 0;

        // Обчислення суми елементів у рядку та стовпці
        for (int j = 0; j < n; ++j) {
            sum += matrix[i][j];
            sum += matrix[j][i];
        }

        // Розміщення суми на головній діагоналі
        matrix[i][i] = sum;
    }

    // Виведення зміненої матриці
    std::cout << "Matrix with sums on the main diagonal:" << std::endl;
    printMatrix(matrix);

    return 0;
}