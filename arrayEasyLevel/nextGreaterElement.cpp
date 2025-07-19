#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2)
{
    std::unordered_map<int, int> nextGreater{};
    std::stack<int> st{};

    for(auto num : nums2)
    {
        while(!st.empty() && num > st.top())
        {
            nextGreater[st.top()] = num;
            st.pop();
        }
        st.push(num);
    }

    std::vector<int> result{};

    for(auto num : nums1)
    {
        if(nextGreater.count(num))
            result.push_back(nextGreater[num]);
        else
            result.push_back(-1);
    }
    return result;
}

int main()
{
    std::vector<int> nums1{4, 1, 2};
    std::vector<int> nums2{1, 3, 4, 2};

    std::cout << "Next greater elements: ";

    for(auto val : nextGreaterElement(nums1, nums2))
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
