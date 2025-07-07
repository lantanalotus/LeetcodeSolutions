#include <iostream>
#include <vector>
#include <span>
#include <ranges>
#include <variant>
#include <string>
#include <algorithm>

using Result = std::variant<int, std::string>;

Result largestPerimeter(const std::span<int> sides)
{
    std::ranges::sort(sides, std::greater{});

    for(std::size_t i{0}; i + 2 < std::size(sides); ++i)
    {
        int a{static_cast<int>(sides[i])};
        int b{static_cast<int>(sides[i + 1])};
        int c{static_cast<int>(sides[i + 2])};

        if(b + c > a)
            return a + b + c;
    }
    return std::string{"No valid triangle can be formed"};    
}

int main()
{
    std::vector<int> input{1, 2, 2, 1};

    Result result{largestPerimeter(input)};

    std::visit([](const auto& value){
        using T = std::decay_t<decltype(value)>;
        if constexpr (std::is_same_v<T, int>)
        {
            std::cout << "Largest perimeter: " << value << '\n';
        }
        else if(std::is_same_v<T, std::string>)
        {
            std::cout << "Error: " << value << '\n';
        }  
    }, result);
    return 0;
}



