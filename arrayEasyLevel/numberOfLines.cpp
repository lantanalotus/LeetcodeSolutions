#include <iostream>
#include <vector>
#include <string>

std::vector<int> numberOfLines(std::vector<int>& width, const std::string& s)
{
    int lines{1};
    int currentWidth{0};

    for(auto ch : s)
    {
        int charWidth = width[ch - 'a'];

        if(currentWidth + charWidth > 100)
        {
            lines++;
            currentWidth = charWidth;
        }
        else
        {
            currentWidth += charWidth;
        }
    }
    return {lines, currentWidth};
}

int main()
{
    std::vector<int> widths{
        4,10,10,10,10,10,10,10,10,10,
        10,10,10,10,10,10,10,10,10,10,
        10,10,10,10,10,10
    };

    std::string s{"bbbcccdddaaa"};

    std::vector<int> result{numberOfLines(widths, s)};
    std::cout << "Lines needed: " << result[0] << '\n' << "Width of last line: " << result[1] << std::endl;

    return 0;

}
