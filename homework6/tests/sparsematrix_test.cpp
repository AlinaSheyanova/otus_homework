#include <gtest/gtest.h>
#include <sstream>
#include "SparseMatrix.h" // Включите заголовочный файл, который содержит вашу реализацию SparseMatrix.

TEST(MatrixTest, SetAndGetValues) {
    Matrix<int, 0> matrix; // Создание матрицы со значением по умолчанию 0

    for (int i = 0; i < 10; ++i) {
        matrix[i][i] = i;          // Заполнение главной диагонали
        matrix[i][9 - i] = 9 - i;  // Заполнение второстепенной диагонали
    }
    EXPECT_EQ(matrix[0][0], 0);
    EXPECT_EQ(matrix[1][1], 1);
    EXPECT_EQ(matrix[9][9], 9);
    EXPECT_EQ(matrix[0][9], 9);
    EXPECT_EQ(matrix[9][0], 0);
    EXPECT_EQ(matrix[0][3], 0);  // Проверка значений за пределами диагоналей
}

TEST(MatrixTest, SizeAndOccupiedCells) {
    Matrix<int, 0> matrix;

    for (int i = 0; i < 10; ++i) {
        matrix[i][i] = i;          // Заполнение главной диагонали
        matrix[i][9 - i] = 9 - i;  // Заполнение второстепенной диагонали
    }

    EXPECT_EQ(matrix.size(), 18); // Должно быть 18 занятых ячеек

    auto cells = matrix.getOccupiedCells();
    EXPECT_EQ(cells.size(), 18);
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}