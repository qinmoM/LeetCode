/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
#include <vector>
#include <algorithm>

using std::vector;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        std::sort(intervals.begin(), intervals.end(), 
            [](const std::vector<int>& a, const std::vector<int>& b) -> bool { return a[0] < b[0]; });
        std::vector<std::vector<int>> result;
        int start = intervals[0][0];
        int endLast = intervals[0][1];
        for (std::vector<int>& vec : intervals)
        {
            if (endLast < vec[0])
            {
                result.push_back({ start, endLast });
                start = vec[0];
                endLast = vec[1];
            }
            else endLast = std::max(vec[1], endLast);
        }
        if (!result.size() || start > result[result.size() - 1][1]) result.push_back({ start, endLast });
        else result[result.size() - 1][1] = std::max(result[result.size() - 1][1], endLast);
        return result;
    }
};
// @lc code=end

