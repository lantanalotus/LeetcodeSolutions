#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> findDisappearedNumbers(std::vector<int>& nums)
{
    for(std::size_t i{0}; i < nums.size(); ++i)
        {
            int index{std::abs(nums[i]) - 1};

            if(nums[index] > 0)
            {
                nums[index] = -nums[index];
            }
        }

    std::vector<int> missingNumbers{};

    for(std::size_t i{0}; i < nums.size(); ++i)
        {
        if(nums[i] > 0)
            {
                missingNumbers.push_back(i + 1);
            }
        }

        return missingNumbers;

}

int main()
{
    std::vector<int> nums1{4, 3, 2, 7, 8, 2, 3, 1};

    for(auto num : findDisappearedNumbers(nums1))
    {
        std::cout << num << " ";
    }
    return 0;
}
