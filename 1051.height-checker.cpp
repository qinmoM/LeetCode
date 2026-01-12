/*
 * @lc app=leetcode id=1051 lang=cpp
 *
 * [1051] Height Checker
 */

// @lc code=start
#include <vector>
#include <algorithm>

using std::vector;

class Solution
{
public:
    int heightChecker(vector<int>& heights)
    {
        std::vector<int> curr(heights);
        std::sort(curr.begin(), curr.end());
        int result = 0;
        for (int i = 0; i < heights.size(); ++i)
        {
            if (heights[i] != curr[i])
                ++result;
        }
        return result;
    }
};
// @lc code=end

