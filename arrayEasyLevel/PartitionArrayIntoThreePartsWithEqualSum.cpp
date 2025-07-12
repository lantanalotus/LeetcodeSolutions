#include <iostream>
#include <vector>
#include <numeric>
#include <chrono>

bool canThreePartsEqualSum(const std::vector<int>& arr)
{
    int totalSum{std::accumulate(arr.begin(), arr.end(), 0)};
    if(totalSum % 3 != 0)
    {
        return false;
    }

    int target{totalSum / 3};
    int currentSum{0};
    int countS{0};

    for(auto i{0}; i < static_cast<int>(arr.size()); ++i)
        {
            currentSum += arr[i];
            if(currentSum == target)
            {
                ++countS;
                currentSum = 0;
                if(countS == 2 && i < static_cast<int>(arr.size() - 1))
                    return true;
            }
        }
        return false;
}
int main()
{
    std::vector arr{0, 2, 2, 0, 1};

    auto startCode{std::chrono::steady_clock::now()};

    auto result{canThreePartsEqualSum(arr)};

    auto endCode{std::chrono::steady_clock::now()};

    auto duration= std::chrono::duration_cast<std::chrono::microseconds>(endCode - startCode);

    std::cout << (result ? "true" : "false") << '\n';
    std::cout << "Execution time: " << duration.count() << " microseconds\n";

    return 0;
}

