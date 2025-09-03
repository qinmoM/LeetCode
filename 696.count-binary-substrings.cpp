/*
 * @lc app=leetcode id=696 lang=cpp
 *
 * [696] Count Binary Substrings
 */

// @lc code=start
#include <string>

using namespace std;

class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        int result = 0;
        int count1 = 0;
        int count2 = 1;
        for (int i = 0; i < s.length() - 1; ++i)
        {
            if (s[i] != s[i + 1])
            {
                result += std::min(count1, count2);
                count1 = count2;
                count2 = 1;
            }
            else
            {
                ++count2;
            }
        }
        result += std::min(count1, count2);
        return result;
    }
};
// @lc code=end

