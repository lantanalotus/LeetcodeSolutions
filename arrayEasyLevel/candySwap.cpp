#include <iostream>
#include <vector>
#include <unordered_set>
#include <ranges>
#include <functional>
#include <algorithm>

std::vector<int> fairCandySwap(const std::vector<int>& aliceSizes, const std::vector<int>& bobSizes)
{
    int sumA{std::ranges::fold_left(aliceSizes, 0, std::plus{})};

    int sumB{std::ranges::fold_left(bobSizes, 0, std::plus{})};

    int delta{static_cast<int>((sumB - sumA) / 2)};

    std::unordered_set<int> bobSet(bobSizes.begin(), bobSizes.end());

    for(auto a : aliceSizes)
    {
        int b{a + delta};
        if(bobSet.contains(b))
            return {a, b};
    }
    return {};
}

int main()
{
    std::vector alice{2};
    std::vector bob{1, 3};

    for(auto candy : fairCandySwap(alice, bob))
        std::cout << candy << " ";
    
    return 0;
}