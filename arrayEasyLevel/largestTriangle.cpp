#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

double largestTriangleArea(const std::vector<std::pair<int, int>>& points)
{
    double maxArea{0.0};
    int n{static_cast<int>(points.size())};

    for(int i{0}; i < n; ++i)
        {
            for(int j{i + 1}; j < n; ++j)
                {
                    for(int k{j + 1}; k < n; ++k)
                        {
                            int x1 = points[i].first;
                            int y1 = points[i].second;

                            int x2 = points[j].first;
                            int y2 = points[j].second;

                            int x3 = points[k].first;
                            int y3 = points[k].second;

                            double area = 0.5 * std::abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));

                            maxArea = std::max(maxArea, area);
                        }

                }
        }
        return maxArea;
}

int main()
{
    std::vector<std::pair<int, int>> points {
    {0, 0}, {0, 1}, {1, 0}, {0, 2}, {2, 0}
    };

    std::cout << "The result is: " <<  largestTriangleArea(points) << std::setprecision(5) << std::endl;

    return 0;

}
