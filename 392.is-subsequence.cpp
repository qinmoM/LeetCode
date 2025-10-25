/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
#include <string>

using std::string;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int index = 0;
        for (char c : t)
        {
            if (index >= s.length())
            {
                return true;
            }
            if (c == s[index])
            {
                ++index;
            }
        }
        return index == s.length();
    }
};
// @lc code=end

