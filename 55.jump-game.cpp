/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
#include <vector>

using std::vector;

class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        int curr = 0;
        while (curr < nums.size() - 1)
        {
            int optimal = curr;
            for (int i = curr + 1; i <= nums[curr] + curr; ++i)
            {
                int temp = nums[i] + i;
                if (temp >= nums.size() - 1)
                {
                    return true;
                }
                if (temp > nums[optimal] + optimal)
                {
                    optimal = i;
                }
            }
            if (optimal == curr)
            {
                return false;
            }
            curr = optimal;
        }
        return true;
    }
};
// @lc code=end

