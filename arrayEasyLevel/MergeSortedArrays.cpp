#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

void mergeArrays(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
    int i{m - 1};
    int j{n - 1};
    int k{m + n - 1};

    while(i >= 0 && j >= 0)
    {
        if(nums1[i] > nums2[j])
        {
            nums1[k--] = nums1[i--];
        }

        else
        {
            nums1[k--] = nums2[j--];
        }
    }

    while(j >= 0)
    {
        nums1[k--] = nums2[j--];
    }
}

void mergeArraysL(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
    nums1.resize(m + n);

    std::ranges::merge(nums1.begin(), nums1.begin() + m, nums2.begin(), nums2.begin() + n, nums1.begin());
}
int main()
{
    std::vector nums1{1, 2, 3, 0, 0, 0};
    std::vector nums2{2, 5, 6};
    int m{3};
    int n{3};

    mergeArrays(nums1, m, nums2, n);

    for(auto num : nums1)
    {
        std::cout << num << " ";
    }

    return 0;
}
