#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
#include <string>

std::vector<std::string> findRestaurant(std::vector<std::string>& list1, std::vector<std::string>& list2)
{
    std::unordered_map<std::string, int> indexMap{};

    std::vector<std::string> result{};

    int minSum = std::numeric_limits<int>::max();

    for(int i{0}; i < static_cast<int>(list1.size()); ++i)
    {
        indexMap[list1[i]] = i;
    }

    for(int j{0}; j < static_cast<int>(list2.size()); ++j)
    {
        if(indexMap.find(list2[j]) != indexMap.end())
        {
            int indexSum = indexMap[list2[j]] + j;
            if(indexSum < minSum)
            {
                minSum = indexSum;
                result = {list2[j]};
            }
            else if(indexSum == minSum)
            {
                result.push_back(list2[j]);
            }
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    std::vector<std::string> list1{"happy", "sad", "good"};
    std::vector<std::string> list2{"sad", "happy", "good"};

    std::cout << "Common strings with least index sum: \n";

    for(const auto& s : findRestaurant(list1, list2))
    {
        std::cout << s << " ";
    }

    std::cout << std::endl;


    return 0;
}
