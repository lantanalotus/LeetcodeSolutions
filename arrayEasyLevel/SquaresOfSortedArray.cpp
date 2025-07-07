#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
#include <span>
#include <chrono>

template <typename T>
constexpr T square(T x)
{
    return x * x;
}

std::vector<int> sortedSquares(const std::span<int> nums)
{
    std::vector<int> result{nums.begin(), nums.end()};

    for(auto& num : result)
    {
        num = square(num);
    } 
    std::ranges::sort(result); 

    return result;
}

int main()
{
    std::vector<int> nums{-4,-1,0,3,10};

    auto start{std::chrono::high_resolution_clock::now()};

    auto result{sortedSquares(nums)};

    auto end{std::chrono::high_resolution_clock::now()};

    auto microSeconds{std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()};

    std::cout << "Time taken: " << microSeconds << " microseconds\n";

    for(auto num: result)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}