#include <iostream>
#include <vector>

double findMaxAverage(std::vector<int>& nums, int k)
{
    double sum{0};
    for(int i{0}; i < k; ++i)
        {
            sum += nums[i];
        }
    double maxSum{sum};

    for(int i{k}; i < static_cast<int>(nums.size()); ++i)
        {
            sum += nums[i] - nums[i - k];
            if(sum > maxSum)
                maxSum = sum;
        }

    return maxSum / k;
}

int main()
{
    std::vector nums{1, 12, -5, -6, 50, 3};
    int k{4};

    std::cout << "Maximum average of subarray of length: " << k << " is: " << findMaxAverage(nums, k) << std::endl;

    return 0;
}
