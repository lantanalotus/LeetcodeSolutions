#include <iostream>
#include <vector>

int islandPerimeter(const std::vector<std::vector<int>>& grid)
{
    std::size_t row{grid.size()};
    std::size_t col {grid[0].size()};

    int perimeter{0};

    for(std::size_t i{0}; i < row; ++i)
        {
            for(std::size_t j{0}; j < col; ++j)
                {
                    if(grid[i][j] == 1)
                    {
                        perimeter += 4;
                        //Check the bottom
                        if(i < row - 1 && grid[i + 1][j] == 1) perimeter -= 1;
                        //Check the top
                        if(i > 0 && grid[i - 1][j] == 1) perimeter -= 1;
                        //Check the right
                        if(j < col - 1 && grid[i][j + 1] == 1) perimeter -= 1;
                        //Check the left
                        if(j > 0 && grid[i][j - 1] == 1) perimeter -= 1;
                    }
                }
        }
        return perimeter;
}

int main()
{
    std::vector<std::vector<int>> grid
    {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}
    };

    std::cout << "Perimeter of the island is: " << islandPerimeter(grid) << std::endl;

    return 0;
}
