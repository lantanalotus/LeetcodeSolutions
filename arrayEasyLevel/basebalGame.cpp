#include <iostream>
#include <vector>
#include <string>

int calPoints(const std::vector<std::string>& ops)
{
    std::vector<int> record{};

    for(const auto& op : ops)
    {
        if(op == "C")
        {
            if(!record.empty())
                record.pop_back();
        }
        else if(op == "D")
        {
            if(!record.empty())
                record.push_back(2 * record.back());
        }
        else if(op == "+")
        {
            int n{static_cast<int>(record.size())};
            if(n >= 2)
                record.push_back(record[n - 1] + record[n - 2]);
        }
        else
        {
            record.push_back(std::stoi(op));
        }
    }

    int total{0};

    for(auto score : record)
    {
        total += score;
    }
    return total;
}

int main()
{
    std::vector<std::string> ops{"5", "2", "C", "D", "+"};

    std::cout << calPoints(ops) << std::endl;
system("pause");

    return 0;
}
