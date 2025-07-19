#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

std::vector<int> sortArrayByParity(std::vector<int>& nums)
{
    const auto isEven = [](int x){return x % 2 == 0;};
    std::ranges::partition(nums, isEven);

    return nums;
}

int main()
{
    std::vector nums{3, 1, 2, 4};

    for(auto x : sortArrayByParity(nums))
    {
        std::cout << x << " ";
    }

    return 0;
}