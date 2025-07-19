#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

int numUniqueEmails(const std::vector<std::string>& emails)
{
    std::unordered_set<std::string> uniqueEmails{};
    for (const auto& email : emails)
    {
        std::string local{};
        std::string domain{};
        bool ignore{false};

        for(std::size_t i{0}; i < email.size(); ++i)
        {
            if(email[i] == '@')
            {
                domain = email.substr(i);
                break;
            }
            if(ignore) {continue;}
            
            if(email[i] == '+')
            ignore = true;
            else if(email[i] != '.')
            local += email[i];
        }
        uniqueEmails.insert(local + domain);
    }
    return uniqueEmails.size();   
}

int main()
{
    std::vector<std::string> emails{
    "test.email+alex@leetcode.com",
    "test.e.mail+bob.cathy@leetcode.com",
    "testemail+david@lee.tcode.com"};

    std::cout << "Number of unique actual emails: " << numUniqueEmails(emails) << std::endl;

    return 0;
}