#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int>& nums)
{
    if(nums.empty()) return 0;

    int i{0};

    for(int j{1}; j < nums.size(); ++j)
        {
            if(nums[j] != nums[i])
            {
                ++i;
                nums[i] = nums[j];
            }
        }
    return i + 1;
}
/* with std library
int removeDuplicates(std::vector<int>& nums)
{
    if(nums.empty()) return 0;

    auto newEnd = std::ranges::unique(nums);

    return std::distance(nums.begin(), newEnd.begin());
}
*/
int main()
{
    std::vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    std::cout << "Number of unique elements are: " << removeDuplicates(nums) << '\n';

    return 0;
}
