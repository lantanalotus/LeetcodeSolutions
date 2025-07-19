#include <iostream>
#include <vector>
#include <iterator>

bool validMoumtainArray(const std::vector<int>& arr)
{
    int n{static_cast<int>(std::size(arr))};

    if(n < 3) return false;

    int i{0};

    while (i + 1 < n && arr[i] < arr[i + 1])
    {
        ++i;
    }

    if(i == 0 || i == n - 1) return false;

    while (i + 1 < n && arr[i] > arr[i + 1])
    {
        ++i;
    }
    return i == n - 1;   
}

int main()
{
    std::vector<std::vector<int>> testCases{
        {2, 1}, {3, 5, 5}, {0, 3, 2, 1}, {0, 1, 2, 3}, {3, 2, 1}, {0, 2, 4, 3, 1}
    };

    for(const auto& arr : testCases)
    {
        std::cout << "Input: [";
        for(std::size_t i{0}; i < std::size(arr); ++i)
        {
            std::cout << arr[i];
            if(i < std::size(arr) - 1)
                std::cout << ", ";
        }
        std::cout << "] => Output: " << (validMoumtainArray(arr) ? "true":"false") << "\n";
    }

    return 0;
}