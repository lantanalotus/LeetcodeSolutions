#include <algorithm>
#include <iostream>
#include <vector>

using Vector3d = std::vector<std::vector<int>>;

int surfaceArea(Vector3d& grid)
{
    int gridSize{static_cast<int>(grid.size())};
    int area{0};

    for(auto i{0}; i < gridSize; ++i)
    {
        for(auto j{0}; j < gridSize; ++j)
        {
            int height{grid[i][j]};
            if(height > 0)
            {
                area += height * 6 - (height - 1) * 2;

                if(i + 1 < gridSize)
                {area -= 2 * std::min(height, grid[i + 1][j]);}

                if(j + 1 < gridSize)
                {area -= 2 * std::min(height, grid[i][j + 1]);}
            }
        }
    }
    return area;
}

int main()
{
    Vector3d grid{{1, 2}, {3, 1}};

    std::cout << "Surface area: " << surfaceArea(grid) << std::endl;

    return 0;
}