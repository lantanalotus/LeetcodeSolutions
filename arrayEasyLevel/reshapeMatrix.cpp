#include <iostream>
#include <vector>

std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>>& mat, int r, int c)
{
    int m{static_cast<int>(mat.size())};
    int n{static_cast<int>(mat[0].size())};

    if(m * n != r * c) return mat;

    std::vector<std::vector<int>> reshaped(r, std::vector<int>(c));

    for(int i{0}; i < m * n; ++i)
        {
            reshaped[i / c][i % c] = mat[i / n][i % n];
        }

    return reshaped;
}

int main()
{
    std::vector<std::vector<int>> mat{{5, 6, 7}, {8, 9, 10}};
    int r{3};
    int c{2};

    std::cout << "Reshaped Matrix: " << '\n';

    for(const auto& row : matrixReshape(mat, r, c))
    {
        for(auto val : row)
        {
            std::cout << val << " ";
        }
        std::cout << '\n';
    }

    return 0;
}
