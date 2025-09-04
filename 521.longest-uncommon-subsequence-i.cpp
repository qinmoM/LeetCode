/*
 * @lc app=leetcode id=521 lang=cpp
 *
 * [521] Longest Uncommon Subsequence I
 */

// @lc code=start
#include <string>

using namespace std;

class Solution
{
public:
    int findLUSlength(string a, string b)
    {
        return a == b ? -1 : std::max(a.length(), b.length());
    }
};
// @lc code=end

