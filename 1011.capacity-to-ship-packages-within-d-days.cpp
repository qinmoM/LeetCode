/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <set>

using std::vector;

class Solution
{
public:
    int shipWithinDays(vector<int>& weights, int days)
    {
        int left = 0;
        int right = 0;
        for (int weight : weights)
        {
            left = std::max(left, weight);
            right += weight;
        }
        while (left < right)
        {
            int all = left;
            int count = 1;
            for (int w : weights)
            {
                if (w > all)
                {
                    ++count;
                    all = left - w;
                }
                else
                {
                    all -= w;
                }
            }

            if (count <= days)
                break;

            ++left;
        }
        return left;

        // std::sort(weights.begin(), weights.end(), std::greater<int>());
        // std::multiset<int> tree;
        // for (int weight : weights)
        // {
        //     if (weights.size() < days)
        //         tree.insert(weight);
        //     else
        //     {
        //         int min = *(tree.begin());
        //         tree.erase(tree.begin());
        //         tree.insert(min + weight);
        //     }
        // }
        // return *(--tree.end());
    }
};
// @lc code=end

