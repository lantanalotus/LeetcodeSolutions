#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

bool isAlienSorted(const std::vector<std::string>& words, const std::string& order)
{
    std::unordered_map<char, std::size_t> rank{};

    for(std::size_t i{0}; i < std::size(order); ++i)
    {
        rank[order[i]] = i;
    }

    for(std::size_t i{0}; i < std::size(words) - 1; ++i)
    {
        const std::string& word1{words[i]};
        const std::string& word2{words[i + 1]};
        bool isOrdered{false};

        for(std::size_t j{0}; j < std::min(std::size(word1), std::size(word2)); ++j)
        {
            if(word1[j] != word2[j])
            {
                if(rank[word1[j]] > rank[word2[j]])
                {
                    return false;
                }
                isOrdered = true;            
                    break;
            }
        }
        if(!isOrdered && std::size(word1) > std::size(word2))
            return false;
    }
    return true;
}

void runTest(int testNum, const std::vector<std::string>& words, const std::string& order)
{
    std::cout << "Test " << testNum << ": " << (isAlienSorted(words, order) ? "true" : "false") << '\n';
}

int main()
{
    runTest(1, {"hello", "leetcode"}, "hlabcdefgijkmnopqrstuvwxyz");
    runTest(2, {"word", "world", "row"}, "worldabcefghijkmnpqstuvxyz");
    runTest(3, {"apple", "app"}, "abcdefghijklmnopqrstuvwxyz");

    return 0;
}