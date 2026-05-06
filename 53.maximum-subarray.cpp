/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
#include <vector>
#include <limits.h>

using std::vector;

class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int res = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            nums[i] = std::max(nums[i], nums[i] + nums[i - 1]);
            res = std::max(res, nums[i]);
        }

        return res;
    }
};
// @lc code=end

