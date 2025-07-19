#include <iostream>
#include <vector>
#include <algorithm>

int findPoisenedDuration(std::vector<int>& timeSeries, int duration)
{
    int total{0};

    for(std::size_t i{0}; i < timeSeries.size() - 1; ++i)
        {
            int gap {timeSeries[i + 1] - timeSeries[i]};

            total += std::min(gap, duration);
        }

        total += duration;

    return total;
}

int main()
{
    std::vector<int> timeSeries{2, 5, 9};

    int duration{3};

    std::cout << "Total poisoned duration: " << findPoisenedDuration(timeSeries, duration) << std::endl;

    return 0;
}
