#include <iostream>
#include <vector>

std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& image)
{
    int n{static_cast<int>(std::size(image))};

    for(int i{0}; i < n; ++i)
    {
        int left{0}; 
        int right{n - 1};

        while (left <= right)
        {
            int temp{image[i][left] ^ 1};
            
            image[i][left] = image[i][right] ^ 1;

            image[i][right] = temp;

            ++left;
            --right;
        }
    }
    return image;
}

void printImage(const std::vector<std::vector<int>>& image)
{
    for(const auto& row : image)
    {
        for(const auto val : row)
        {
            std::cout << val << " ";
        }
        std::cout << '\n';
    }
}

int main()
{
    std::vector<std::vector<int>> image{{1, 1, 0}, {1, 0, 1}, {0, 0, 0}};

    std::cout << "Original Image:\n";
    printImage(image);

    std::cout << "\nFlipped and Inverted Image:\n";
    printImage(flipAndInvertImage(image));

    return 0;
}