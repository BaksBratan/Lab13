#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// ������� ��� ��������� ������� �� �����
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int element : row) {
            std::cout << element << "\t";
        }
        std::cout << std::endl;
    }
}

int main() {
    // ����������� ���������� ���������� �����
    std::srand(std::time(0));

    // ��������� �������
    const int n = 5; // ����� ��������� ������� �� ��������

    // ���������� ������� ����������� �������
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = std::rand() % 201 - 100; // ��������� ����� � ������� �� -100 �� 100
        }
    }

    // ��������� ��������� �������
    std::cout << "Initial matrix:" << std::endl;
    printMatrix(matrix);
    std::cout << std::endl;

    // ���������� ��� �� ��������� �� ������� �������
    for (int i = 0; i < n; ++i) {
        int sum = 0;

        // ���������� ���� �������� � ����� �� �������
        for (int j = 0; j < n; ++j) {
            sum += matrix[i][j];
            sum += matrix[j][i];
        }

        // ��������� ���� �� ������� �������
        matrix[i][i] = sum;
    }

    // ��������� ������ �������
    std::cout << "Matrix with sums on the main diagonal:" << std::endl;
    printMatrix(matrix);

    return 0;
}