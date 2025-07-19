#include <iostream>
#include <unordered_map>
#include <vector>
//#include <cmath>
#include <span>

bool containNearbyDuplicate(const std::vector<int>& nums, int k)
{
    std::unordered_map<int, int> lastSeenIndex{};

    for(int i{0}; i < static_cast<int>(nums.size()); ++i)
        {
            if(lastSeenIndex.find(nums[i]) != lastSeenIndex.end())
            {
                if(i - lastSeenIndex[nums[i]] <= k)
                    {return true;}
            }
            lastSeenIndex[nums[i]] = i;
        }
        return false;
}

int main()
{
    std::vector<int> nums{1, 2, 3, 1, 2};
    int k{3};

    std::cout << std::boolalpha << containNearbyDuplicate(nums, k) << std::endl;

    return 0;
}
