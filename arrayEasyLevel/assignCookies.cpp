#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

int findContentChildren(std::vector<int>& g, std::vector<int>& s)
{
    std::ranges::sort(g);
    std::ranges::sort(s);

    std::size_t i{0};
    std::size_t j{0};

    while(i < g.size() && j < s.size())
    {
        if(s[j] >= g[i])
        {
            ++i;
        }
        ++j;
    }
    return static_cast<int>(i);
}

int main()
{
    using TestCase = std::pair<std::vector<int>, std::vector<int>>;

    std::vector<TestCase> testCases {
        {{1, 2, 3}, {1, 1}},
        {{1, 2}, {1, 2, 3}}
        };

        int testNum{1};

        for(auto [g, s] : testCases)
        {
            std::cout << "Test " << testNum++ << " Output: " << findContentChildren(g, s) << '\n';
        }

    return 0;
}
