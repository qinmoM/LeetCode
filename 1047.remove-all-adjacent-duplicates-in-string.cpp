/*
 * @lc app=leetcode id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 */

// @lc code=start
#include <string>

using std::string;

class Solution
{
public:
    string removeDuplicates(string s)
    {
        std::string res;
        for (char c : s)
        {
            if (res.empty())
            {
                res.push_back(c);
                continue;
            }
            if (res.back() == c)
            {
                res.pop_back();
                continue;
            }
            res.push_back(c);
        }
        return res;
    }
};
// @lc code=end

