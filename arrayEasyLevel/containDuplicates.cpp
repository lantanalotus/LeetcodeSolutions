#include <iostream>
#include <vector>
#include <unordered_set>
#include <span>

bool containDuplicatesL(const std::vector<int>& nums)
{
    if(nums.empty()) return false;

    std::unordered_set<int> seen{};

    for(auto num : nums)
    {
        if(seen.count(num))
        {
            return true;
        }
        seen.insert(num);
    }
    return false;
}
bool containDuplicates(const std::span<const int> nums) {
    std::unordered_set<int> seen;
    for (int num : nums) {
        if (seen.count(num)) return true;
        seen.insert(num);
    }
    return false;
}


int main()
{
    std::vector<int> nums{1, 2, 3, 1};
    std::vector<int> nums1{1, 2, 3, 4};

    std::cout << std::boolalpha;

    std::cout << "Is there duplicates? " << containDuplicates(nums) << std::endl;
    return 0;
}
