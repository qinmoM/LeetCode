/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
#include <vector>

using std::vector;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        std::vector<std::vector<int>> result;
        int start = newInterval[0];
        bool overlap = false;
        for (int i = 0; i < intervals.size(); ++i)
        {
            if (!overlap && intervals[i][1] < newInterval[0])
            {
                result.push_back(intervals[i]);
                continue;
            }
            if (!overlap)
            {
                start = std::min(start, intervals[i][0]);
                overlap = true;
            }
            if (newInterval[1] <= intervals[i][1])
            {
                if (newInterval[1] >= intervals[i][0])
                    result.push_back({ start, intervals[i][1] });
                else
                {
                    result.push_back({ start, newInterval[1] });
                    result.push_back(intervals[i]);
                }
                for (int j = i + 1; j < intervals.size(); ++j)
                    result.push_back(intervals[j]);
                break;
            }
            else if (i == intervals.size() - 1)
            {
                result.push_back({ start, std::max(newInterval[1], intervals[i][1]) });
                break;
            }
        }
        if (!overlap) result.push_back(newInterval);
        return result;
    }
};
// @lc code=end

