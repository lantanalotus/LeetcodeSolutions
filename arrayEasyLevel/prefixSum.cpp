#include <iostream>
#include <vector>

class NumArray
{
private:
    std::vector<int> prefixSum{};
public:
    NumArray(const std::vector<int>& nums)
    {
        int n{static_cast<int>(nums.size())};

        prefixSum.resize(n + 1, 0);

        for(int i{0}; i < n; ++i)
            {
                prefixSum[i + 1] = prefixSum[i] + nums[i];
            }
    }
    int sumRange(int left, int right)
    {
        return prefixSum[right + 1] - prefixSum[left];
    }
};

int main()
{
    std::vector<int> nums{1, 2, 3, 4, 5};

    NumArray numArray(nums);

    std::cout << "sumRange(0, 4): " << numArray.sumRange(0, 4) << '\n';
    //15
    return 0;
}
