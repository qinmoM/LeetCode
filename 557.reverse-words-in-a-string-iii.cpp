/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int begin = 0;
        int end = 0;
        while (begin < s.size())
        {
            while (++end < s.size() && ' ' != s[end]);
            std::reverse(s.begin() + begin, s.begin() + end);
            while (++end < s.size() && ' ' == s[end]);
            begin = end;
        }
        return s;
    }
};
// @lc code=end

