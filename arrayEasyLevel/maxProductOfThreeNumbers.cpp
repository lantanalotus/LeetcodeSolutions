#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

int maximumProduct(std::vector<int>& nums)
{
    std::ranges::sort(nums);

    int n{static_cast<int>(nums.size())};

    int product1{nums[n - 1] * nums[n - 2] * nums[n - 3]};

    int product2{nums[0] * nums[1] * nums[n - 1]};

    return std::max(product1, product2);
}

int main()
{
    std::vector nums{-10, -10, 1, 2, 3};

    std::cout << "Maximum product of three numbers: " << maximumProduct(nums) << std::endl;

    return 0;
}
