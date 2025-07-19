#include <vector>
#include <iostream>
#include <unordered_set>

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2)
{
    std::unordered_set<int> set1{nums1.begin(), nums1.end()};

    std::unordered_set<int> resultSet{};

    for(auto num : nums2)
    {
        if(set1.count(num))
        {
            resultSet.insert(num);
        }
    }

    return std::vector<int>(resultSet.begin(), resultSet.end());
}

int main()
{
    std::vector nums1{4, 9, 5};
    std::vector nums2{9, 4, 9, 8, 4};

    for(auto num : intersection(nums1, nums2))
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
