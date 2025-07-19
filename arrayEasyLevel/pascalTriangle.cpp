#include <iostream>
#include <vector>

std::vector<std::vector<int>> generatePascal(int numRows)
{
    std::vector<std::vector<int>> triangle{};

    for(int i{0}; i < numRows; ++i)
        {
            std::vector<int> row(i + 1, 1);

            for(int j{1}; j < i; ++j)
                {
                    row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
                }

                triangle.push_back(row);
        }
        return triangle;
}

int main()
{
    int numRows{5};

    auto triangle = generatePascal(numRows);

    for(const auto& row : triangle)
    {
        for(int val : row)
        {
            std::cout << val << " ";
        }
        std::cout << '\n';
    }

    return 0;
}
