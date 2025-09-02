#include <iostream>
#include <vector>
#include <string>

std::string longestCommoPrefix(const std::vector<std::string>& strs)
{
    if(strs.empty()) return "";

    std::string prefix{strs[0]};// Start with the first word as prefix

    for(std::size_t i{1}; i < strs.size(); ++i)
        {
            std::size_t j{0};
            // Compare characters until they differ or one string ends
            while(j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j])
            {
                ++j;
            }
            // Shrink prefix to only the matching part
            prefix = prefix.substr(0, j);
            if(prefix.empty()) return "";
        }
        return prefix;
}

int main()
{
    std::vector<std::string> example{"flower", "flow", "flight"};

    std::cout << "Longest common prefix: " << longestCommoPrefix(example) << std::endl;

    return 0;
}
