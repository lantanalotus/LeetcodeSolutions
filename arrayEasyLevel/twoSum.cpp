#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target)
{
    std::unordered_map<int,int> map{};

    for(int i{0}; i < nums.size(); ++i)
        {
            int compliment = target - nums[i];

            if(map.count(compliment))
            {
                return {map[compliment], i};
            }
            map[nums[i]] = i;
        }
        return {};
}

int main()
{
    std::vector<int> nums{2, 7, 11, 15};

    int target{9};

    std::vector<int> result = twoSum(nums, target);

    std::cout << "[" << result[0] << ", " << result[1] << "]" << '\n';

    return 0;
}
