#include <iostream>
#include <vector>
#include <string>
#include <iterator>

int minDeletionSize(const std::vector<std::string>& strs)
{
    int numCols{static_cast<int>(std::size(strs[0]))};
    int numRows{static_cast<int>(std::size(strs))};
    int count{0};
    //Loop through each column
    for(int col{0}; col < numCols; ++col)
    {//Check if the column is sorted
        for(int row{0}; row < numRows - 1; ++row)
        {
            if(strs[row][col] > strs[row + 1][col])
            {
                ++count;
                break;
            }
        }
    }

    return count;
}