#include <iostream>
#include <vector>

bool canPlaceFlowers(std::vector<int>& flowerBed, int n)
{
    int sizeF{static_cast<int>(flowerBed.size())};

    for(int i{0}; i < sizeF; ++i)
        {
            if(flowerBed[i] == 0)
            {
                bool emptyLeft{i == 0 || flowerBed[i - 1] == 0};
                bool emptyRight{i == sizeF - 1 || flowerBed[i + 1] == 0};

                if(emptyLeft && emptyRight)
                {
                    flowerBed[i] = 1;
                    --n;
                    if(n == 0)
                        return true;
                }
            }
        }

    return n <= 0;
}

int main()
{
    std::vector<std::pair<std::vector<int>, int>> testCases
    {
        {{1, 0, 0, 0, 1}, 1},
        {{1, 0, 0, 0, 1}, 2},
        {{0, 0, 0, 0, 0}, 3},
    };

    for(std::size_t i{0}; i < testCases.size(); ++i)
        {
            auto [flowerBed, n] = testCases[i];
            bool result{canPlaceFlowers(flowerBed, n)};

            std::cout << "Test " << i + 1 << ": " << (result ? " true" : "false") << std::endl;
        }

    return 0;
}
