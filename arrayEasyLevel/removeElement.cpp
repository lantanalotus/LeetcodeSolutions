#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

int removeElementsL(std::vector<int>& nums, int val)
{
    if(nums.empty()) return 0;

    int i{0};

    for(std::size_t j{0}; j < nums.size(); ++j)
        {
            if(nums[j] != val)
            {
                nums[i] = nums[j];
                ++i;
            }
        }
    return i;
}

int removeElements(std::vector<int>& nums, int val)
{
        auto newEnd = std::ranges::remove(nums, val);
        return static_cast<int>(newEnd.begin() - nums.begin());
}

int main()
{
    std::vector<int> nums{0,1,2,2,3,0,4,2};
    int val{2};
    int k = removeElements(nums, val);

    std::cout << "Number of elements not equal to " << val << ": " << k << '\n';
    std::cout << "Modified array: ";
    for(int i{0}; i < k; ++i)
    {
        std::cout << nums[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}
