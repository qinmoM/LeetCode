/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
#include <string>

using std::string;

class Solution
{
public:
    string countAndSay(int n)
    {
        return recursion(n, "1");
    }

    std::string recursion(int n, std::string s)
    {
        if (1 == n)
        {
            return s;
        }

        std::string temp;
        int count = 1;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                ++count;
            }
            else
            {
                temp += std::to_string(count) + s[i];
                count = 1;
            }
        }
        temp += std::to_string(count) + s[s.length() - 1];
        return recursion(n - 1, temp);
    }

};
// @lc code=end

