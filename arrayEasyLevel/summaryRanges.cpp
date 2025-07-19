#include <iostream>
#include <span>
#include <vector>
#include <string>
#include <string_view>

std::vector<std::string> summaryRanges(std::span<const int> nums)
{
    std::vector<std::string> result{};

    if(nums.empty()) return result;

    int start{nums[0]};

    for(std::size_t i{1}; i < nums.size(); ++i)
    {
        if(nums[i] != nums[i - 1] + 1)
        {
            int end{nums[i - 1]};

            if(start == end)
            {
                result.push_back(std::to_string(start));
            }
            else
            {
                result.push_back(std::to_string(start) + "->" + std::to_string(end));
            }
            start = nums[i];
        }
    }
    int end = nums.back();

        if(start == end)
        {
            result.push_back(std::to_string(start));
        }
        else
        {
            result.push_back(std::to_string(start) + "->" + std::to_string(end));
        }
    return result;
}

int main()
{
    std::vector<int> nums{0, 2, 3, 4, 6, 8, 9};

    for(std::string_view range : summaryRanges(nums))
    {
        std::cout << range << " ";
    }
    std::cout << std::endl;

    return 0;
}