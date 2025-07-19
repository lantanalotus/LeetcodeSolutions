#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <unordered_set>
#include <algorithm>
#include <ranges>

std::vector<std::string> findWords(const std::vector<std::string>& words)
{
    std::unordered_set<char> row1{'q','w','e','r','t','y','u','i','o','p'};
    std::unordered_set<char> row2{'a','s','d','f','g','h','j','k','l'};
    std::unordered_set<char> row3{'z','x','c','v','b','n','m'};

    std::vector<std::string> result{};

    for(std::string_view word : words)
    {
        std::string lowerWord{};
        lowerWord.resize(word.size());

        std::ranges::transform(word, lowerWord.begin(), ::tolower);

        std::unordered_set<char>* row{nullptr};

        if(row1.count(lowerWord[0]))
            row = &row1;
        else if(row2.count(lowerWord[0]))
            row = &row2;
        else if(row3.count(lowerWord[0]))
            row = &row3;

        bool valid {std::ranges::all_of(lowerWord, [&](char c){return row->count(c);})};

        if(valid) result.emplace_back(word);
    }
    return result;
}

int main()
{
    std::vector<std::string> words{"Hello", "Alaska", "Dad", "Peace"};

    for(std::string_view word : findWords(words))
    {
        std::cout << word << '\n';
    }

    return 0;
}
