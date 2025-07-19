#include <iostream>
#include <vector>
#include <algorithm>

using Vector3d = std::vector<std::vector<int>>;

int projectionArea(Vector3d& grid)
{
    int gridSize{static_cast<int>(grid.size())};
    int topView{0};
    int frontView{0};
    int sideView{0};

    for(int i{0}; i < gridSize; ++i)
    {
        int rowMax{0};
        int colMax{0};

        for(int j{0}; j < gridSize; ++j)
        {
            if(grid[i][j] > 0) {topView++;}

            rowMax = std::max(rowMax, grid[i][j]);
            colMax = std::max(colMax, grid[j][i]);
        }
        frontView += rowMax;
        sideView += colMax;        
    }
    return topView + frontView + sideView;
}

int main()
{
    Vector3d grid{{1, 2}, {3, 4}};

    std::cout << "Total Projection Area: " << projectionArea(grid) << std::endl;

    return 0;
}