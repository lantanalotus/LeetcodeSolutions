#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

int maxCandyTypes(const std::vector<int>& candyType)
{
    std::unordered_set<int> uniqueTypes{candyType.begin(), candyType.end()};

    int maxEatable {static_cast<int>(candyType.size()) / 2};

    return std::min(static_cast<int>(uniqueTypes.size()), maxEatable);
}

int main()
{
    std::vector candyType{1, 1, 2, 3};

    std::cout << maxCandyTypes(candyType) << std::endl;

    return 0;
}
