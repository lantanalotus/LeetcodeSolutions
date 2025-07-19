#include <iostream>
#include <vector>
#include <algorithm>

int minCostClimbingStairs(const std::vector<int>& cost)
{
    int n{static_cast<int>(cost.size())};
    std::vector<int> dp(n);

    dp[0] = cost[0];
    dp[1] = cost[1];

    for(int i{2}; i < n; ++i)
    {
        dp[i] = cost[i] + std::min(dp[i - 1], dp[i - 2]);
    }

    return std::min(dp[n - 1], dp[n - 2]);
}

int main()
{
    std::vector<int> cost{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};

    std::cout << "Minimum cost to reach the top is: " << minCostClimbingStairs(cost) << std::endl;
    
    return 0;
}