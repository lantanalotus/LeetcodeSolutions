#include <iostream>
#include <vector>
#include <queue>
#include <span>

int lastStoneWeight(const std::span<int> stones)
{
    std::priority_queue<int> maxHeap(stones.begin(), stones.end());

    while(maxHeap.size() > 1)
    {
        int stone1{maxHeap.top()};
        maxHeap.pop();
        int stone2{maxHeap.top()};
        maxHeap.pop();

        if(stone1 != stone2)
            maxHeap.push(stone1 - stone2);
    }
    return maxHeap.empty() ? 0 : maxHeap.top();
}

int main()
{
    std::vector stones{2, 7, 4, 1, 8, 1};
    std::cout << "Last stone weight: " << lastStoneWeight(stones) << std::endl;

    return 0;

}
