#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> findErrorNums(std::vector<int>& nums)
{

    std::unordered_set<int> seen{};

    int duplicate{-1};
    int actualSum{0};

    for(auto num : nums)
    {
        if(seen.count(num))
        {
            duplicate = num;
        }
        else
        {
            seen.insert(num);
            actualSum += num;
        }
    }
    int n{static_cast<int>(nums.size())};
    int expectedSum = n * (n + 1) / 2;
    int missing{expectedSum - actualSum};

    return std::vector<int>{duplicate, missing};
}

int main()
{
    std::vector<int> nums{1, 2, 2, 4};

    std::vector<int> result{findErrorNums(nums)};

    std::cout << "Duplicate: " << result[0] << '\n' << "Missing: " << result[1] << std::endl;

    return 0;
}
