/*
 * @lc app=leetcode id=495 lang=cpp
 *
 * [495] Teemo Attacking
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration)
    {
        int result = duration;
        for (int i = 0; i < timeSeries.size() - 1; ++i)
        {
            result += std::min(timeSeries[i + 1] - timeSeries[i], duration);
        }
        return result;
    }
};
// @lc code=end

