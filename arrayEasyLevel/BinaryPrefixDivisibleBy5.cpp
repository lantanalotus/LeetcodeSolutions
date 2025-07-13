#include <iostream>
#include <vector>
#include <span>
#include <chrono>

std::vector<bool> prefixesDivBy5(const std::span<const int> nums)
{
    std::vector<bool> result{};
    int current{0};
    for(auto bit : nums)
    {
        current = ((current << 1) + bit) % 5;
        result.emplace_back(current == 0);
    }
    return result;
}

int main()
{
    std::vector nums{1, 0, 1};

    auto startCode{std::chrono::steady_clock::now()};

    auto result{prefixesDivBy5(nums)};

    auto endCode{std::chrono::steady_clock::now()};

    auto duration{std::chrono::duration_cast<std::chrono::microseconds>(endCode - startCode)};

    std::cout << "Input: ";
    for(auto bit : nums)
    {
        std::cout << bit;
    }

    std::cout << "\nOutput: ";
    for(auto val : result)
    {
        std::cout << (val ? "true" : "false") << " ";
    }
    std::cout << "\nExecution Time: " << duration.count() << " microseconds\n";

    return 0;

}
