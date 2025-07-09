#include <iostream>
#include <vector>
#include <array>
#include <chrono>

using Vector2D = std::vector<std::vector<char>>; 
using Array2D = std::array<std::array<int, 2>, 4>;

int numRookCaptures(Vector2D& board)
{
    int rookRow{-1};
    int rookCol{-1};
    int boardSize{8};

    for(auto i{0}; i < boardSize; ++i)
    {
        for(auto j{0}; j < boardSize; ++j)
        {
            if(board[i][j] == 'R')
            {
                rookRow = i;
                rookCol = j;
                break;
            }
        }
    }
    int captures{0};
    Array2D directions{{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

    for(const auto& dir : directions)
    {
        int row{rookRow + dir[0]};
        int col{rookCol + dir[1]};

        while (row >= 0 && row < boardSize && col >= 0 && col < boardSize)
        {
            if(board[row][col] == 'B') break;
            if(board[row][col] == 'p')
            {
                ++captures;
                break;
            }
            row += dir[0];
            col += dir[1];
        }        
    }
    return captures;
}

int main()
{
    Vector2D board{
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','p','.','.','.','.'},
        {'.','.','.','R','.','.','.','p'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','p','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'}
    };

    auto start{std::chrono::steady_clock::now()};

    int result{numRookCaptures(board)};

    auto end{std::chrono::steady_clock::now()};

    std::chrono::duration<double, std::micro> duration{end - start};

    std::cout << "Captures: " << result << std::endl;
    std::cout << "Execution time: " << duration.count() << " microseconds" << std::endl;

    return 0;
}