#include <iostream>
#include <vector>
#include <span>
#include <chrono>
#include <ranges>
#include <numeric>
#include <algorithm>

int largestSumAfterKNegation(const std::span<int> nums, int k)
{
    std::ranges::sort(nums);

    for(auto& num : nums)
    {
        if(k > 0 && num < 0)
        {
            num = -num;
            --k;
        }
    }
    if(k % 2 == 1)
    {
        auto& minElement{*std::ranges::min_element(nums)};
        minElement = -minElement;
    }
    return std::accumulate(nums.begin(), nums.end(), 0);
}

int main()
{
    std::vector nums{2, -3, -1, 5, -4};
    int k{2};
    
    using namespace std::chrono_literals;

    auto start{std::chrono::steady_clock::now()};
    auto result{largestSumAfterKNegation(nums, k)};
    auto end{std::chrono::steady_clock::now()};

    auto duration{(end - start) / 1us};

    std::cout << "Maximum sum: " << result << '\n';
    std::cout << "Execution time: " << duration << " microseconds" << '\n';

    return 0;
}