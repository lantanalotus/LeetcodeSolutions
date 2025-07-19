#include <iostream>
#include <vector>

std::vector<int> plusOne(std::vector<int>& digits)
{
	for(int i = digits.size() - 1; i >= 0; --i)
	{
		if(digits[i] < 9)
		{
			digits[i] += 1;
			return digits;
		}
		digits[i] = 0;
	}
	digits.insert(digits.begin(), 1);
	return digits;
}

void printVector(const std::vector<int>& v)
{
    for(auto num : v)
    {
        std::cout << num << " ";
    }
    std::cout << '\n';
}

int main()
{
    std::vector digits1{1, 2, 3};
    std::vector digits2{4, 3, 2, 1};
    std::vector digits3{9};

    std::vector result1 = plusOne(digits1);
    std::vector result2 = plusOne(digits2);
    std::vector result3 = plusOne(digits3);

    std::cout << "Result 1: ";
    printVector(result1);
    std::cout << "Result 2: ";
    printVector(result2);
    std::cout << "Result 3: ";
    printVector(result3);

    return 0;
}
