#include <iostream>
#include <vector>

int dominantIndex(const std::vector<int>& nums)
{
    int numsSize{static_cast<int>(nums.size())};
    int maxIndex{0};

    for(int i{1}; i < numsSize; ++i)
    {
        if(nums[i] > nums[maxIndex])
            maxIndex = i;
    }
    for(int i{0}; i < numsSize; ++i)
    {
        if(i != maxIndex && nums[maxIndex] < 2 * nums[i])
            return -1;
    }
    return maxIndex;
}

int main() 
{
    std::vector<int> nums{3, 6, 1, 0};
    std::cout << "Result for [3, 6, 1, 0]: " << dominantIndex(nums) << '\n';
    
    return 0;
}
