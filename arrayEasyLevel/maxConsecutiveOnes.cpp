#include <iostream>
#include <vector>
#include <algorithm>

int findMaxConsecutiveOnes(const std::vector<int>& nums)
{
    int maxCount{0};
    int currentCount{0};

    for(auto num : nums)
    {
        if(num == 1)
        {
            ++currentCount;
            maxCount = std::max(maxCount, currentCount);
        }
        else
        {
            currentCount = 0;
        }
    }
    return maxCount;
}

int main()
{
    std::vector<int> nums1{1, 1, 0, 1, 1, 1};
    std::vector<int> nums2{1, 0, 1, 1, 0, 1};

    std::cout << "Max consecutive is (Example 1) " << findMaxConsecutiveOnes(nums1) << '\n';
    std::cout << "Max consecutive is (Example 2) " << findMaxConsecutiveOnes(nums2) << std::endl;

    return 0;
}
