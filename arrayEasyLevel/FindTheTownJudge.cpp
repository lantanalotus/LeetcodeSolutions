#include <iostream>
#include <vector>
#include <string>
#include <variant>

using Vector2D = std::vector<std::vector<int>>; 

std::variant<int, std::string> findTownJudge(int totalNumberOfPeaple, const Vector2D& trustRelationships)
{
    std::vector<int> trustScore(totalNumberOfPeaple + 1, 0);//index 0 is unused
    
    for(const std::vector<int>& trustPair : trustRelationships)
    {
        int trustingPerson{trustPair[0]};
        int trustedPerson{trustPair[1]};
        
        --trustScore[trustingPerson];
        ++trustScore[trustedPerson];
    }
    for(auto person{1}; person <= totalNumberOfPeaple; ++person)
    {
        if(trustScore[person] == totalNumberOfPeaple - 1)
            return person;
    }
    return std::string{"No judge found"};
}

int main()
{
    int totalNumberOfPeople{3};
    Vector2D trustRelationships {{1, 3}, {2, 3}};

    auto result{findTownJudge(totalNumberOfPeople, trustRelationships)};

    auto printResult = [](const auto& value)
    {
        using T = std::decay_t<decltype(value)>;
        if constexpr(std::is_same_v<T, int>)
        {
            std::cout << "Judje found: Person " << value << '\n';
        }
        else if constexpr(std::is_same_v<T, std::string>)
        {
            std::cout << value << '\n';
        }
    };
    std::visit(printResult, result);    

    return 0;
}