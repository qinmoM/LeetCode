/*
 * @lc app=leetcode id=775 lang=cpp
 *
 * [775] Global and Local Inversions
 */

// @lc code=start
#include <vector>

using std::vector;

class Solution
{
public:
    bool isIdealPermutation(vector<int>& nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > i + 1 || nums[i] < i - 1)
                return false;
        }
        return true;
    }
};
// @lc code=end

