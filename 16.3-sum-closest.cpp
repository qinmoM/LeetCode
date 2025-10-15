/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;

class Solution
{
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        std::sort(nums.begin(), nums.end());
        int identical = INT_MAX;
        int add = 0;
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            int temp = target - nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                int difference = temp - nums[left] - nums[right];
                if (identical > std::abs(difference))
                {
                    add = nums[i] + nums[left] + nums[right];
                    identical = std::abs(difference);
                }
                if (difference == 0)
                {
                    return add;
                }
                else if (difference > 0)
                {
                    ++left;
                }
                else
                {
                    --right;
                }
            }
        }
        return add;
    }
};
// @lc code=end

