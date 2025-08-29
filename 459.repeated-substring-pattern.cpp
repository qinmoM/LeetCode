/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
#include <string>

using namespace std;

class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        return (s + s).substr(1, s.size() * 2 - 2).find(s) != string::npos;
    }
};
// @lc code=end

