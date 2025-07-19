#include <iostream>
#include <vector>

bool isTeoplitzMatrix(const std::vector<std::vector<int>>& matrix)
{
    int m{static_cast<int>(matrix.size())};
    int n{static_cast<int>(matrix[0].size())};

    for(int i{1}; i < m; ++i)
    {
        for(int j{1}; j < n; ++j)
        {
            if(matrix[i][j] != matrix[i - 1][j - 1])
                return false;
        }
    }
    return true;
}

int main()
{
    std::vector<std::vector<int>> matrix{
        {1, 2, 3, 4},
        {5, 1, 2, 3},
        {9, 5, 1, 2}
    };

    std::cout << "Matrix is Teoplitz: " << (isTeoplitzMatrix(matrix) ? "true" : "false") << std::endl;

    return 0;
}