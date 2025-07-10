#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <span>

std::vector<std::string> commonChars(const std::span<const std::string> words)
{
    std::vector<int> minFreq(26, 100); //allocate 26 integers with value 100
    int allEngLetters{26};

    for(const auto& word : words)
    {
        std::vector<int> freq(26, 0); //allocate 26 integers with value 0
        for(auto chr : word)
        {
            //this uses ASCII to access a character 
            //Example: 'a' = ASCII 97/ 'b' = ASCII '98'/ 98 - 97 = 1 
            //++freq[1] means the second letter of the English alphabet/ 
            //That is 'b' / ++ freq[1] increment count of b by 1
            ++freq[chr - 'a']; 
        }
        for(auto index{0}; index < allEngLetters; ++index)
        {   //minFrq[1] 'b' = min(minfreq[1] value '1', freq[1]  value'100') 
            //it will choose minimum value that is '1' 
            minFreq[index] = std::min(minFreq[index], freq[index]);
        }
    }
        std::vector<std::string> result{};
        for(auto index{0}; index < allEngLetters; ++index)
        {   //Convert to character using ASCII 97 + 1 = 98 that is 'b'
            char letter{static_cast<char>('a' + index)};
            for(auto count{0}; count < minFreq[index]; ++count)
            {   //create 1 copy of the letter //if 3 then three copy bbb
                //emplace_back creates it at place more efficient than push_back 
                //which makes a copy
                result.emplace_back(1, letter);
            }
        }   
        return result;
}

int main()
{
    //add this for using us
    using namespace std::chrono_literals;
    
    const std::vector<std::string> words{"bella", "label", "roller"};
    //start timing
    const auto start{std::chrono::steady_clock::now()};

    const auto result{commonChars(words)};
    //end timing
    const auto end{std::chrono::steady_clock::now()};
    
    //us is measure unit for microseconds 
    //this line of code converts initial unit ot microseconds
    const auto microseconds{(end - start) / 1us};
    
    std::cout << "Commons characters: ";
    for(const auto& chr : result)
    {
        std::cout << chr << " ";
    }
    std::cout << "\nFunction execution time: " << microseconds << " microseconds\n";

    return 0;
}