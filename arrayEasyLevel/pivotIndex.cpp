#include <iostream>
#include <vector>

int pivotIndex(const std::vector<int>& nums)
{
    int totalSum{0};

    for(auto num : nums)
    {
        totalSum += num;
    }

    int leftSum{0};
    for(int i{0}; i < static_cast<int>(nums.size()); ++i)
        {
            int rightSum = {totalSum - leftSum - nums[i]};
            if(leftSum == rightSum)
                {return i;}
            leftSum += nums[i];
        }
    return -1;
}

int main()
{
    std::vector nums{1, 7, 3, 6, 5, 6};
    int pivot{pivotIndex(nums)};

    if(pivot != -1)
    {
        std::cout << "Pivot index: " << pivot << '\n';
    }
    else
    {
        std::cout << "No pivot index found." << std::endl;
    }
    return 0;
}
