#include <iostream>
#include <vector>
#include <algorithm>
#include <span>
#include <ranges>
#include <chrono>

std::vector<int> addToArrayForm(const std::span<const int> num, int k)
{
    std::vector<int> result{};
    int index{static_cast<int>(std::size(num) - 1)};

    while (index >= 0 || k > 0)
    {
        if(index >= 0)
        {
            k += num[index];
            index--;
        }
        result.push_back(k % 10);
        k /= 10;
    }
    std::ranges::reverse(result);
    
    return result;
}

int main()
{
    std::vector num{9, 9, 9};
    int k{5};

    auto start{std::chrono::high_resolution_clock::now()};
    auto result{addToArrayForm(num, k)};
    auto end{std::chrono::high_resolution_clock::now()};

    std::chrono::duration<double, std::micro> duration{end - start};

    std::cout << "Time taken: " << duration.count() << " microseconds\n";

    std::cout << "Result: ";
    for(auto digit : result)
    {
        std::cout << digit << " ";
    }
    std::cout << std::endl;

    return 0;
}

