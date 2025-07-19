#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int findShortestSubArray(const std::vector<int>& nums)
{
    std::unordered_map<int, int> countFreq{};
    std::unordered_map<int, int> firstIndex{};

    int numsSize = static_cast<int>(nums.size());
    int degree{0};
    int minLength{numsSize};

    for(int i{0}; i < numsSize; ++i)
        {
            int num{nums[i]};
            if(firstIndex.find(num) == firstIndex.end())
            {
                firstIndex[num] = i;
            }
            countFreq[num]++;

            if(countFreq[num] > degree)
            {
                degree = countFreq[num];
                minLength = i - firstIndex[num] + 1;
            }
            else if(countFreq[num] == degree)
            {
                minLength = std::min(minLength, i - firstIndex[num] + 1);
            }
        }
        return minLength;
}

int main()
{
    std::vector<int> nums{1, 2, 2, 3, 1};

    std::cout << "Output: " << findShortestSubArray(nums) << std::endl;

    return 0;
}
