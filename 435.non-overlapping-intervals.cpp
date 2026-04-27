/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <limits.h>

using std::vector;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        std::sort(intervals.begin(), intervals.end(),
            [](const std::vector<int>& a, const std::vector<int>& b) -> bool
            {
                return a[1] < b[1];
            }
        );
        int last = INT_MIN;
        int res = 0;

        for (const std::vector<int>& vec : intervals)
        {
            if (vec[0] >= last)
            {
                ++res;
                last = std::max(last, vec[1]);
            }
        }

        return intervals.size() - res;
    }
};
// @lc code=end

