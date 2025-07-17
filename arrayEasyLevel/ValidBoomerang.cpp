#include <iostream>
#include <vector>

using Vector2D = std::vector<std::vector<int>>;

bool isBoomerang(Vector2D& points)
{
    if(points[0] == points[1] || points[0] == points[2]
       || points[1] == points[2])
        return false;

    int x1{points[0][0]};
    int y1{points[0][1]};

    int x2{points[1][0]};
    int y2{points[1][1]};

    int x3{points[2][0]};
    int y3{points[2][1]};

    return (y2 - y1)*(x3 - x1) != (y3 - y1)*(x2 - x1);
}

int main()
{
    Vector2D test1{{1, 1}, {2, 3}, {3, 2}}; //true
    Vector2D test2{{1, 1}, {2, 2}, {3, 3}}; //false
    Vector2D test3{{1, 1}, {1, 1}, {3, 2}}; //false

    std::cout << std::boolalpha;

    std::cout << "Test 1: " << isBoomerang(test1) << '\n';
    std::cout << "Test 2: " << isBoomerang(test2) << '\n';
    std::cout << "Test 3: " << isBoomerang(test3) << '\n';

    return 0;
}
