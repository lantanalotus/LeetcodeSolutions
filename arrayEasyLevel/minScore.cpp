#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

int minScore(std::vector<int>& nums, int k)
{
    int minVal{*std::ranges::min_element(nums)};
    int maxVal{*std::ranges::max_element(nums)};

    int score{maxVal - minVal - 2 * k};

    return std::max(0, score);
}

int main()
{
    std::vector nums{1, 3, 6};

    std::cout << "Minimum score is: " << minScore(nums, 3) << std::endl;

    return 0;
}