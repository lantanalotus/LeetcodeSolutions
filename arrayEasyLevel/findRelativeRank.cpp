#include <vector>
#include <iostream>
#include <string_view>
#include <algorithm>
#include <ranges>
#include <functional>

std::vector<std::string> findRelativeRanks(const std::vector<int>& score)
{
    std::size_t n{score.size()};

    std::vector<std::pair<int, int>> scoreIndex{};

    for(std::size_t i{0}; i < n; ++i)
        {
            scoreIndex.emplace_back(score[i], i);
        }

    std::ranges::sort(scoreIndex, std::greater<>(), [](const auto& p){return p.first;});

    std::vector<std::string> result(n);

    constexpr std::string_view medals[]{"Gold Medal", "Silver Medal", "Bronze Medal"};

    for(std::size_t i{0}; i < n; ++i)
        {
            int index = scoreIndex[i].second;
            if(i < 3)
                result[index] = std::string(medals[i]);
            else
                result[index] = std::to_string(i + 1);
        }
    return result;
}

int main()
{
    std::vector score{10, 3, 8, 9, 4};

    for(const auto& rank : findRelativeRanks(score))
    {
        std::cout << rank << " ";
    }
    return 0;
}
