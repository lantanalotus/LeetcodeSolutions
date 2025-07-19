#include <iostream>
#include <limits>
#include <vector>

int maxProfit(const std::vector<int>& prices)
{
    int minPrice = std::numeric_limits<int>::max();
    int maxProfit{0};

    for(auto price : prices)
    {
        if(price < minPrice)
        {
            minPrice = price;
        }
        else
        {
            maxProfit = std::max(maxProfit, price - minPrice);
        }
    }
    return maxProfit;
}

int main()
{
    std::vector prices{7, 1, 5, 3, 6, 4};

    std::cout << "Max profit for prices: " << maxProfit(prices) << std::endl;

    return 0;
}
