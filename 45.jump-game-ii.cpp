/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
#include <vector>
#include <iostream>

using std::vector;

class Solution
{
public:
    int jump(vector<int>& nums)
    {
        if (nums.size() <= 1)
        {
            return 0;
        }
        int lastIndex = nums[0];
        int currIndex = 0;
        int result = 1;
        while (lastIndex < nums.size() - 1)
        {
            result += 1;
            int maxIndex = currIndex + 1;
            for (int i = currIndex + 1; i <= nums[currIndex] + currIndex; ++i)
            {
                int temp = nums[i] + i;
                if (temp >= lastIndex)
                {
                    maxIndex = i;
                    lastIndex = temp;
                    if (lastIndex >= nums.size() - 1)
                    {
                        return result;
                    }
                }
            }
            currIndex = maxIndex;
        }
        return result;
    }
};
// @lc code=end

