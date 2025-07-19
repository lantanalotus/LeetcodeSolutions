#include <iostream>
#include <vector>
#include <algorithm>

int maxCount(int m, int n, std::vector<std::vector<int>>& ops)
{
    int commonRows{m};
    int commonCols{n};

    for(const auto& op : ops)
    {
        commonRows = std::min(commonRows, op[0]);
        commonCols = std::min(commonCols, op[1]);
    }
    return commonRows * commonCols;
}

int main()
{
    int m{3};
    int n{3};

    std::vector<std::vector<int>> ops{{2, 2}, {3, 3}};

    std::cout << "Number of maximum elements: " << maxCount(m, n, ops) << std::endl;

    return 0;
}
