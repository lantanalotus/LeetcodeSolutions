#include <iostream>
#include <vector>
#include <span>
#include <unordered_set>
#include <variant>
#include <string>

std::variant<int, std::string> repeatedNTimes(const std::span<const int> nums)
{
    std::unordered_set<int> seen{};

    for(auto num : nums)
    {
        if(seen.contains(num))
           {return num;}

        seen.insert(num);
    }
    return std::string{"No repeated number found"};    
}

int main()
{
    std::vector<int> nums{1, 2, 3, 3};
    std::vector<int> nums1{3, 4, 5, 6};

    auto result{repeatedNTimes(nums1)};

    if(std::holds_alternative<int>(result))
    {
        std::cout << "Repeated number: " << std::get<int>(result) << '\n';
    }
    else
    {
        std::cout << std::get<std::string>(result) << '\n';
    }
    //For using without if/else block
    std::visit([](const auto& value){std::cout << value << '\n';}, result);

    return 0;
}
