/*
 * @lc app=leetcode id=930 lang=cpp
 *
 * [930] Binary Subarrays With Sum
 */

// @lc code=start
#include <vector>

using std::vector;

class Solution
{
public:
    int numSubarraysWithSum(vector<int>& nums, int goal)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            int all = 0;
            for (int j = i; j < nums.size(); ++j)
            {
                all += nums[j];
                if (all == goal)
                    ++count;
            }
        }
        return count;
    }
};
// @lc code=end

