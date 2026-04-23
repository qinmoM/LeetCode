/*
 * @lc app=leetcode id=331 lang=cpp
 *
 * [331] Verify Preorder Serialization of a Binary Tree
 */

// @lc code=start
#include <string>
#include <vector>

using std::string;

class Solution
{
public:
    bool isValidSerialization(string preorder)
    {
        int temp = -1;
        std::vector<int> stack;

        // for (int i = 0; i < preorder.size(); ++i)
        for (char c : preorder)
        {
            if (stack.size() && -1 == *stack.begin()) return false;

            if ('#' == c)
            {
                while (stack.size() > 1 && -1 == stack.back())
                {
                    stack.pop_back();
                    stack.pop_back();
                }

                stack.push_back(-1);
            }
            else if (',' == c)
            {
                if (-1 != temp) stack.push_back(temp);
                temp = -1;
            }
            else
            {
                if (-1 == temp) temp = 0;
                temp = temp * 10 + c - '0';
            }
        }
        if (-1 != temp) stack.push_back(temp);

        return stack.size() == 1 && stack.back() == -1;
    }
};
// @lc code=end

