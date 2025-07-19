#include <iostream>
#include <vector>
#include <string>
#include <cctype>

std::string shortestCompleteWord(std::string licensePlate, std::vector<std::string>& words)
{
    std::vector<int> targetCount(26, 0);

    for(auto c : licensePlate)
    {
        if(std::isalpha(c))
        {
            targetCount[std::tolower(c) - 'a']++;
        }
    }

    std::string result{};

    for(const auto& word : words)
    {
        std::vector<int> wordCount(26, 0);

        for(auto c : word)
        {
            wordCount[c - 'a']++;
        }

        bool valid{true};

        for(int i{0}; i < 26; ++i)
        {
            if(wordCount[i] < targetCount[i])
            {
                valid = false;
                break;
            }
        }

        if(valid && (result.empty() || word.length() < result.length()))
        {
            result = word;
        }
    }
    return result;
}

int main()
{
    std::string licensePlate{"1s3 PSt"};

    std::vector<std::string> words{"step", "steps", "stripe", "stepple"};

    std::cout << "Shortest completing word: " << shortestCompleteWord(licensePlate, words) << std::endl;

    return 0;
}