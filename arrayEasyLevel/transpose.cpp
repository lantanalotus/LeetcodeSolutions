#include <vector>
#include <iostream>

using Matrix = std::vector<std::vector<int>>;

Matrix transpose(const Matrix& matrix)
{
    int rowSize{static_cast<int>(matrix.size())};
    int colSize{static_cast<int>(matrix[0].size())};

    Matrix result(colSize, std::vector<int>(rowSize));

    for(int row{0}; row < rowSize; ++row)
    {
        for(int col{0}; col < colSize; ++col)
        {
            result[col][row] = matrix[row][col];
        }
    }

    return result;
}

void printMatrix(const Matrix& matrix)
{
    for(const auto& row : matrix)
    {
        for(auto val : row)
        {
            std::cout << val << " ";
        }
        std::cout << '\n';
    }
}

int main()
{
    Matrix matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    std::cout << "The original matrix output: \n";
    printMatrix(matrix);

    Matrix result{transpose(matrix)};

    std::cout << "The transpose matrix output: \n";

    printMatrix(result);

    return 0;
}