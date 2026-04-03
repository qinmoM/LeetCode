/*
 * @lc app=leetcode id=1029 lang=cpp
 *
 * [1029] Two City Scheduling
 */

// @lc code=start
// #include <map>
#include <vector>
#include <algorithm>

using std::vector;

class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>>& costs)
    {
        std::sort(costs.begin(), costs.end(),
            [](const std::vector<int>& a, const std::vector<int>& b)
            {
                return a[0] - a[1] < b[0] - b[1];
            }
        );

        int res = 0;
        for (int i = 0; i < costs.size(); ++i)
        {
            if (i < costs.size() / 2)
                res += costs[i][0];
            else
                res += costs[i][1];
        }
        return res;

        // std::multimap<int, std::vector<int>> map;
        // for (const std::vector<int>& vec : costs)
        //     map.insert({vec[1] - vec[0], vec});
        //
        // int all = 0;
        // for (int i = 0; i < costs.size(); ++i)
        // {
        //     auto it = map.begin();
        //
        //     if (i < costs.size() / 2)
        //         all += it->second[1];
        //     else
        //         all += it->second[0];
        //
        //     map.erase(it);
        // }
        // return all;
    }
};
// @lc code=end

