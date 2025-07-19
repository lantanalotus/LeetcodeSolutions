#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<int> shortestDistanceToChar(const std::string& inputString, char targetChar)
{
    int length{static_cast<int>(inputString.size())};
    
    std::vector<int> distances(length, length);

    int lastSeenTarget{-length};

    for(int index{0}; index < length; ++index)
    {
        if(inputString[index] == targetChar)
            {lastSeenTarget = index;}
        distances[index] = index - lastSeenTarget;
    }
    lastSeenTarget = 2 * length;

    for(int index{length - 1}; index >= 0; --index)
    {
        if(inputString[index] == targetChar)
            {lastSeenTarget = index;}
       
        distances[index] = std::min(distances[index], lastSeenTarget - index);
    }

    return distances;
}

int main()
{
    std::string inputString{"abacb"};
    char targetChar{'b'};

    for(auto distance : shortestDistanceToChar(inputString, targetChar))
    {
        std::cout << distance << " ";
    }
    std::cout << std::endl;

    return 0;
}