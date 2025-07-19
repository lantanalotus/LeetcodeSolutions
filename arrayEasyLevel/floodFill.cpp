#include <iostream>
#include <vector>

class Solution
{
public:

    void dfs(std::vector<std::vector<int>>& image, int sr, int sc, int color, int originalColor)
    {
        int imageRowSize{static_cast<int>(image.size())};
        int imageColSize{static_cast<int>(image[0].size())};

        //Check if the current position out of bounds
        if(sr < 0 || sr >= imageRowSize || sc < 0 || sr >= imageColSize)
            return;
        //If the current pixel is not of the original color, or already colored, stop
        if(image[sr][sc] != originalColor || image[sr][sc] == color)
            return;
        //Change th color
        image[sr][sc] = color;
        //Recurse in all four directions
        dfs(image, sr + 1, sc, color, originalColor); //Down
        dfs(image, sr - 1, sc, color, originalColor); //Up
        dfs(image, sr, sc + 1, color, originalColor); //Right
        dfs(image, sr, sc - 1, color, originalColor); //Left
    }

    std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color)
    {
        int originalColor = image[sr][sc];
        if(originalColor != color)
        {
            dfs(image, sr, sc, color, originalColor);
        }
        return image;
    }
};

int main()
{
    Solution sol{};

    std::vector<std::vector<int>> image{
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    int sr{1};
    int sc{1};
    int color{2};

    std::vector<std::vector<int>> result{sol.floodFill(image, sr, sc, color)};

    for(const auto& row : result)
    {
        for(auto val : row)
        {
            std::cout << val << " ";
        }
        std::cout << '\n';
    }

    return 0;
}
