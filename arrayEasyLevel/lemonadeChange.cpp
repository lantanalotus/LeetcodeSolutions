#include <iostream>
#include <vector>

bool lemonadeChange(const std::vector<int>& bills)
{
    int five{0};
    int ten{0};

    for(auto bill : bills)
    {
        switch (bill)
        {
        case 5:
            five++;
            break;
        case 10:
            if(five == 0) return false;
            five--;
            ten++;
            break;
        case 20:
            if(ten > 0 && five > 0)
            {
                ten--;
                five--;
            }
            else if(five >= 3)
            {
                five -= 3;
            }
            else
            {
                return false;
            }
            break;
        }
    }
    return true;
}

int main()
{
    std::vector<int> bills{5, 5, 5, 10, 20};

    std::cout << "Result is " << std::boolalpha << lemonadeChange(bills) << '\n';

    return 0;
}