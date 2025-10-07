/*
 * @lc app=leetcode id=896 lang=cpp
 *
 * [896] Monotonic Array
 */

// @lc code=start
class Solution
{
public:
    bool isMonotonic(vector<int>& nums)
    {
        bool isAscend = (nums[0] < nums[nums.size() - 1] ? true : false);
        for (int i = 1; i < nums.size(); ++i)
        {
            if ((isAscend && nums[i] < nums[i - 1]) || (!isAscend && nums[i] > nums[i - 1]))
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

