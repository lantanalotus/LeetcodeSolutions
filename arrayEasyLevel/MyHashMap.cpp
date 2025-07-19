#include <iostream>
#include <vector>

class MyHashMap
{
private:
    struct Node
    {
        int key{};
        int value{};
        Node* next{};
        Node(int k, int v) : key{k}, value{v}, next{nullptr}{}
    };
    static const int SIZE{101};
    std::vector<Node*> table{};

    int hashF(int key)const {return key % SIZE;}

public:
    MyHashMap() : table(SIZE, nullptr){}

    void put(int key, int value)
    {
        int index{hashF(key)};
        Node* curr{table[index]};

        while(curr)
        {
            if(curr->key == key)
            {
                curr->value = value;
                return;
            }
            curr = curr->next;
        }
        Node* newNode{new Node(key, value)};
        newNode->next = table[index];
        table[index] = newNode;
    }
    int get(int key)
    {
        int index{hashF(key)};
        Node* curr{table[index]};

        while(curr)
        {
            if(curr->key == key)
            {
                return curr->value;
            }
            curr = curr->next;
        }
        return -1;
    }
    void removeK(int key)
    {
        int index{hashF(key)};
        Node* curr{table[index]};
        Node* prev{nullptr};

        while(curr)
        {
            if(curr->key == key)
            {
                if(prev)
                    prev->next = curr->next;
                else
                    {
                        table[index] = curr->next;
                        
                    }
                delete curr;
                return;
            }   
            prev = curr;
            curr = curr->next;         
        }
        
    }
    ~MyHashMap()
    {
        for(Node* head : table)
        {
            while(head)
            {
                Node* next{head->next};
                delete head;
                head = next;
            }
        }
    }
};

int main()
{
    MyHashMap myMap{};
    myMap.put(1, 10);
    myMap.put(2, 20);
    myMap.put(3, 30);

    std::cout << "Get key 2: " << myMap.get(2) << '\n';//20

    myMap.put(2, 99);

    std::cout << "Updated key 2: " << myMap.get(2) << '\n';//99

    myMap.removeK(2);

    std::cout << "After removal key 2: " << myMap.get(2) << '\n'; //-1

    return 0;
}
