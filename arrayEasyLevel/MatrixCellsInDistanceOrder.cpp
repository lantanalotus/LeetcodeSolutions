#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <cmath>
#include <ranges>

using Vector2D = std::vector<std::vector<int>>;


Vector2D allCellsDistOrder(int rows, int cols, int rCenter, int cCenter)
{
    Vector2D result(rows * cols);
    int index{0};

    for(auto row{0}; row < rows; ++row)
        {
            for(auto col{0}; col < cols; ++col)
                {
                    result[index++] = {row, col};
                }
        }
        auto compareByDistance = [rCenter, cCenter](const std::vector<int>& cell1, const std::vector<int>& cell2)
        {
            int dist1{std::abs(cell1[0] - rCenter) + std::abs(cell1[1] - cCenter)};
            int dist2{std::abs(cell2[0] - rCenter) + std::abs(cell2[1] - cCenter)};
            return dist1 < dist2;
        };

        std::ranges::sort(result, compareByDistance);
        return result;
}
int main()
{
    int rows{5};
    int cols{5};
    int rCenter{2};
    int cCenter{2};

    auto startCode{std::chrono::steady_clock::now()};
    Vector2D sortedCells{allCellsDistOrder(rows, cols, rCenter, cCenter)};
    auto endCode{std::chrono::steady_clock::now()};

    auto duration{std::chrono::duration<double, std::milli>(endCode - startCode)};
    std::cout << "Execution time: " << duration.count() << " ms\n";

    std::cout << "First 10 cells sorted by Manhattan distance:\n";

    for(std::size_t i{0}; i < 10 && i < sortedCells.size(); ++i)
        {
            std::cout << "(" << sortedCells[i][0] << ", " << sortedCells[i][1] << ")\n";
        }

    return 0;
}
