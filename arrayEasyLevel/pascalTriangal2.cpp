#include <iostream>
#include <vector>

std::vector<int> getRow(int rowIndex)
{
    std::vector<int> row(rowIndex + 1, 0);

    row[0] = 1;

    for(int i{1}; i <= rowIndex; ++i)
        {
            for(int j{i}; j >= 1; --j)
                {
                    row[j] += row[j - 1];
                }
        }
    return row;
}

int main()
{
    int rowIndex{3};

    std::vector result = getRow(rowIndex);

    std::cout << "Pascal's Triangle Row " << rowIndex << ": ";

    for(auto num : result)
    {
        std::cout << num << " ";
    }

    std::cout << std::endl;

    return 0;
}
