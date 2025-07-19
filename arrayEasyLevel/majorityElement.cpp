#include <iostream>
#include <vector>

int majorityElement(const std::vector<int>& nums)
{
    int majorityCandidate{0};
    int countMajority{0};

    for(auto num : nums)
    {
        if(countMajority == 0)
        {
            majorityCandidate = num;
        }

        if(num == majorityCandidate)
           {
               ++countMajority;
           }
        else
            {
                --countMajority;
            }

    }
    return majorityCandidate;
}

int main()
{
    std::vector<int> nums{2, 2, 1, 2};

    std::cout << "Majority Element: " << majorityElement(nums) << std::endl;

    return 0;
}

