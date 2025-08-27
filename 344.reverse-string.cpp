/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    void reverseString(vector<char>& s)
    {
        for (int i = 0; i < s.size() / 2; ++i)
        {
            std::swap(s[i], s[s.size() - i - 1]);
        }
    }
};
// @lc code=end

