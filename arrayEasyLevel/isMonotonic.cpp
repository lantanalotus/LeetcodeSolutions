#include <vector>
#include <iostream>

bool isMonotonic(const std::vector<int>& nums)
{
    bool increasing{true};
    bool decreasing{true};

    for(std::size_t i{1}; i < nums.size(); ++i)
    {
        if(nums[i] > nums[i - 1])
        {
            decreasing = false;
        }
        if(nums[i] < nums[i - 1])
        {
            increasing = false;
        }
    }
    return increasing || decreasing;
}

void printFunc(std::vector<int>&& nums)
{
    std::cout << std::boolalpha << isMonotonic(nums) << '\n';
}
int main()
{
    printFunc({1, 2, 2, 3});
    printFunc({6, 5, 4, 4});
    printFunc({1, 3, 2});

    return 0;     
}