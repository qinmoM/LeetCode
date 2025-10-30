/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
#include <vector>
#include <map>

using std::vector;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>>& points)
    {
        std::multimap<int, int> tree;
        for (std::vector<int>& vec : points)
        {
            tree.insert({vec[1], vec[0]});
        }
        int arrows = 0;
        while (!tree.empty())
        {
            int target = tree.begin()->first;
            std::map<int, int>::iterator it = tree.begin();
            while (it != tree.end())
            {
                if (it->second <= target)
                {
                    it = tree.erase(it);
                }
                else
                {
                    ++it;
                }
            }
            ++arrows;
        }
        return arrows;
    }
};
// @lc code=end

