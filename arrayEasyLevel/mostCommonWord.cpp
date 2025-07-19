#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

std::string mostCommonWord(std::string paragraph, std::vector<std::string>& banned)
{
    for(auto& ch : paragraph)
    {
        if(std::ispunct(ch))
            ch = ' ';
        else
            ch = std::tolower(ch);
    }

    std::unordered_set<std::string> bannedSet(banned.begin(), banned.end());

    std::unordered_map<std::string, int> wordCount{};

    std::istringstream inputStream{paragraph};

    std::string word{};

    std::string mostCommon{};

    int maxCount{0};

    while(inputStream >> word)
    {
        if(bannedSet.find(word) == bannedSet.end())
        {
            wordCount[word]++;
            if(wordCount[word] > maxCount)
            {
                maxCount = wordCount[word];
                mostCommon = word;
            }
        }
    }
    return mostCommon;
}

int main()
{
    std::string paragraph{"Bob hit a ball, the hit BALL flew far after it was hit."};

    std::vector<std::string> banned{"hit"};

    std::cout << "Most common word, not banned: " << mostCommonWord(paragraph, banned) << std::endl;

    return 0;
}