#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

class MyHashSet
{
private:

    static const int hashSize{1000};
    std::vector<std::vector<int>> buckets{};
    int hashSet(int key){return key % hashSize;}

public:

    MyHashSet(){buckets.resize(hashSize);}

    void addKey(int key)
    {
        int index{hashSet(key)};

        if(!containsKey(key))
            buckets[index].push_back(key);
    }
    void removeKey(int key)
    {
        int index{hashSet(key)};

        auto& bucket{buckets[index]};

        auto it = std::ranges::find(bucket, key);

        if(it != bucket.end())
            bucket.erase(it);
    }
    bool containsKey(int key)
    {
        int index{hashSet(key)};

        const auto& bucket = buckets[index];

        return std::ranges::find(bucket, key) != bucket.end();
    }
};

int main()
{
    MyHashSet mySet{};

    mySet.addKey(1);
    mySet.addKey(2);

    std::cout << mySet.containsKey(1) << '\n';
    std::cout << mySet.containsKey(3) << '\n';

    mySet.addKey(2);
    std::cout << mySet.containsKey(2) << '\n';

    mySet.removeKey(2);
    std::cout << mySet.containsKey(2) << '\n';

    return 0;
}
