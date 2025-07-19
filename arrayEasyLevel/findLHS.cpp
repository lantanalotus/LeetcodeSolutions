#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <unordered_map>

int findLHS(const std::vector<int>& nums)
{   //for storing frequency
    std::unordered_map<int, int> freq{};
    //count frequency
    for(auto num : nums)
        ++freq[num];

    //use ranges to iterate over map entries
    auto view = freq | std::ranges::views::filter([&freq](const auto& pairF)
                            {return freq.contains(pairF.first + 1); });

    int maxLength{0};

    for(const auto& [num, countF] : view)
    {
        maxLength = std::max(maxLength, countF + freq[num + 1]);
    }

    return maxLength;
}

int main()
{
    std::vector nums{4, 4, 5, 6, 6, 6, 7};

    std::cout << "Longest Harmonious Subsequence Length: " << findLHS(nums) << std::endl;

    return 0;
}
