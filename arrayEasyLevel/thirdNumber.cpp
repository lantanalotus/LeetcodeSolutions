#include <iostream>
#include <vector>
#include <limits>

int thirdMax(std::vector<int>& nums)
{
    long first{std::numeric_limits<long>::min()};
    long second{std::numeric_limits<long>::min()};
    long third{std::numeric_limits<long>::min()};

    for(auto num : nums)
    {
        if(num == first || num == second || num == third)
            {continue;}

        if(num > first)
        {
            third = second;
            second = first;
            first = num;
        }
        else if(num > second)
        {
            third = second;
            second = num;
        }
        else if(num > third)
        {
            third = num;
        }
    }
    return (third == std::numeric_limits<long>::min()) ? first : third;
}

void print(std::vector<int>& nums)
{
    std::cout << "The out put for: [";

    for(std::size_t i{0}; i < nums.size(); ++i)
    {
         std::cout << nums[i] << " ";
    }
    std::cout << "] is " << thirdMax(nums) << std::endl;

}

int main()
{
    std::vector nums1{3, 2, 1};
    std::vector nums2{1, 2};
    std::vector nums3{2, 2, 3, 1};

    print(nums1);
    print(nums2);
    print(nums3);


    return 0;
}
