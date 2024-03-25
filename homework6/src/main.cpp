#include <iostream>
#include <cstdlib>

#include "SparseMatrix.h"

int main(int argc, char** argv)
{

    Matrix<int, 0> matrix; // Создание матрицы со значением по умолчанию 0

    for (int i = 0; i < 10; ++i) {
        matrix[i][i] = i;          // Заполнение главной диагонали
        matrix[i][9 - i] = 9 - i;  // Заполнение второстепенной диагонали
    }


    for (int i = 1; i <= 8; ++i) {
        for (int j = 1; j <= 8; ++j) {
            std::cout << matrix[i][j];
            if (j != 8)
                std::cout << ' ';
        }
        std::cout << '\n';
    }

    std::cout << "Number of occupied cells: " << matrix.size() << std::endl;
    for (auto cell : matrix.getOccupiedCells()) {
        std::cout << "cell[" << cell.x << "," << cell.y << "] = " << cell.value << std::endl;
    }
    ((matrix[100][100] = 314) = 0) = 217;
    std::cout << matrix[100][100] << std::endl;
    return EXIT_SUCCESS;
}