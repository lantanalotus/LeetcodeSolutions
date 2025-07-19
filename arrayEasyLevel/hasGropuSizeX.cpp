#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>

bool hasGroupsSizeX(const std::vector<int>& deck)
{
    std::unordered_map<int,int> cardCount{};

    for(auto card : deck)
    {
        cardCount[card]++;
    }
    int gcdValue{0};

    for(const auto& [_, freq] : cardCount)
    {
        gcdValue = std::gcd(gcdValue, freq);
    }
    return gcdValue >= 2;
}

int main()
{
    std::vector deck{1, 1, 1, 2, 2, 3, 3, 3};

std::cout << "Can the deck partitioned? " << std::boolalpha << 
hasGroupsSizeX(deck) << std::endl;

    return 0;
}