#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> sortArrayPartyII(std::vector<int>& nums)
{
    int i{0};
    int j{1};
    int numsSize{static_cast<int>(std::size(nums))};

    while (i < numsSize && j < numsSize)
    {
        if(nums[i] % 2 == 0)
        {
            i += 2;
        }
        else if(nums[j] % 2 == 1)
        {
            j += 2;
        }
        else
        {
            std::swap(nums[i], nums[j]);
            i += 2;
            j += 2;
        }
    }
    return nums;
}

int main()
{
    std::vector nums{4, 2, 5, 7};

    std::cout << "Original: ";
    for(auto x : nums)
    {
        std::cout << x << " ";
    }
    std::cout << "\nSorted: ";
    for(auto x : sortArrayPartyII(nums))
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}