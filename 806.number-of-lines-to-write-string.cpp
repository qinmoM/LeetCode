/*
 * @lc app=leetcode id=806 lang=cpp
 *
 * [806] Number of Lines To Write String
 */

// @lc code=start
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution
{
public:
    vector<int> numberOfLines(vector<int>& widths, string s)
    {
        int count = 1;
        int pixels = 0;
        for (char c : s)
        {
            int temp = widths[c - 'a'];
            if (pixels + temp > 100)
            {
                ++count;
                pixels = 0;
            }
            pixels += temp;
        }
        return { count, pixels };
    }
};
// @lc code=end

