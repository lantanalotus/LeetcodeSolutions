#include <iostream>
#include <vector>
#include <array>

int heightChecker(std::vector<int>& heights)
{
    std::array<int, 101> countHeights{};

    for(auto height : heights)
        ++countHeights[height];
    // step 2

    int index{0};
    int result{0};
    int maxHeight{100};

    for(auto height{1}; height <= maxHeight; ++height)
        {
            while(countHeights[height] > 0)
            {
                if(heights[index] != height)
                {
                    ++result;
                }
                ++index;
                --countHeights[height];
            }

        }
        return result;
}

int main()
{
    std::vector heights{1, 1, 4, 2, 1, 3};
    std::cout << "Result " << heightChecker(heights) << std::endl;

    return 0;
}
