#include <iostream>
#include <vector>
#include <utility> // for std::pair
#include <ranges>
#include <algorithm>

int searchInsertL(const std::vector<int>& nums, int target)
{
    int left{0};
    int right = nums.size() - 1;

    while(left <= right)
    {
        int mid = left + (right - left) / 2;

        if(nums[mid] == target)
            return mid;
        else if(nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

int searchInsert(const std::vector<int>& nums, int target)
{
    auto it = std::ranges::lower_bound(nums, target);
    return it - nums.begin();
}


int main()
{
    std::vector<std::pair<std::vector<int>, int>> testCases{
        {{1, 3, 5, 6}, 5},
        {{1, 3, 5, 6}, 2},
        {{1, 3, 5, 6}, 7}
    };

    for(const auto& [nums, target] : testCases)
    {
        std::cout << "Index for target " << target << ": " << searchInsert(nums, target) << '\n';
    }

    return 0;
}
