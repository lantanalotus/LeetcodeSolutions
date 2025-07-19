#include <iostream>
#include <vector>

char nextGreaterLetter(std::vector<char>& letters, char target)
{
    int left{0};
    int right{static_cast<int>(letters.size())};

    while(left < right)
    {
        int mid = left + (right - left) / 2;

        if(letters[mid] <= target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return letters[left % letters.size()];
}

int main()
{
    std::vector<char> letters{'c', 'f', 'j'};

    std::cout << "Output " << nextGreaterLetter(letters, 'a') << std::endl;

    return 0;
}
