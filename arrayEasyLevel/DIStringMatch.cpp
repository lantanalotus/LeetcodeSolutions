#include <iostream>
#include <vector>
#include <string>

std::vector<int> diStringMatch(const std::string& str)
{
    int strLength{static_cast<int>(str.length())};
    int low{0};
    int high{strLength};

    std::vector<int> result{};

    for(auto chr : str)
    {
        if(chr == 'I')
            result.push_back(low++);
        else //chr == 'D'
            result.push_back(high--);
    }
    
    result.push_back(low); //Append the last number (low == high)
    return result;
}

int main()
{
    std::string str{"IDID"};
    for(auto num : diStringMatch(str))
        std::cout << num << " ";

    return 0;
}