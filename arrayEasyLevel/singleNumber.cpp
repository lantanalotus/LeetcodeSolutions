#include <iostream>
#include <vector>

[[nodiscard]]
int singleNumber(const std::vector<int>& nums) noexcept
{
    int result{0};

    for(auto num : nums)
    {
        result ^= num;
    }
    return result;
}

int main()
{
    std::vector<int> nums{4, 1, 2, 1, 2};

    std::cout << "Single number is: " << singleNumber(nums) << std::endl;
    return 0;
}
