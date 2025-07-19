#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

int uniqueMorseRepresentaions(const std::vector<std::string>& words)
{
    std::vector<std::string> morse{
        ".-","-...","-.-.","-..",".","..-.","--.","....","..",
        ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
        "...","-","..-","...-",".--","-..-","-.--","--.."
    };

    std::unordered_set<std::string> uniqueTransformations{};

    for(const auto& word : words)
    {
        std::string code{};
        for(auto c : word)
        {
            code += morse[c - 'a'];
        }
        uniqueTransformations.insert(code);
    }

    return uniqueTransformations.size();
}

int main()
{
    std::vector<std::string> words{"gin", "zen", "gig", "msg"};

    std::cout << "Number of unique Morse code representations: " << uniqueMorseRepresentaions(words) << std::endl;

    return 0;
}
