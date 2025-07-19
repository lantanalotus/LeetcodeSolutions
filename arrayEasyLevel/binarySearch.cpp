#include <iostream>
#include <vector>

int searchBinary(const std::vector<int>& nums, int target)
{
    int left{0};
    int right{static_cast<int>(nums.size() - 1)};

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
    return -1;
}

int main()
{
    std::vector nums{-1, 0, 3, 5, 9, 12};
    int target{9};

    std::cout << "Index of " << searchBinary(nums, target) << std::endl;

    return 0;
}
