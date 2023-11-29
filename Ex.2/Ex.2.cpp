#include <iostream>
#include <vector>
#include <limits>

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
    // ��������� �������
    const int numRows = 3; // ����� ��������� ������� �� ��������
    const int numCols = 4;

    // ���������� ������� ����������� �������
    std::vector<std::vector<int>> matrix(numRows, std::vector<int>(numCols, 0));
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            matrix[i][j] = rand() % 100; // ��������� ����� � ������� �� 0 �� 99
        }
    }

    // ��������� ��������� �������
    std::cout << "Initial matrix:" << std::endl;
    printMatrix(matrix);
    std::cout << std::endl;

    // ����������� �� ��������� ������������� �������� ��� ������� �����
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