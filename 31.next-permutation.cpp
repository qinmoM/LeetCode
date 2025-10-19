/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution
{
public:
    void nextPermutation(vector<int>& nums)
    {
        int index = nums.size() - 1;
        while (index > 0 && nums[index - 1] >= nums[index]) --index;

        if (0 == index)
            return std::reverse(nums.begin(), nums.end());

        std::vector<int>::iterator min_ = nums.begin() + index;
        int temp = *(nums.begin() + index - 1);
        for (std::vector<int>::iterator it = nums.begin() + index + 1; it < nums.end(); ++it)
        {
            if (*it > temp && *it < *min_)
            {
                min_ = it;
            }
        }
        std::swap(*min_, *(nums.begin() + index - 1));
        std::sort(nums.begin() + index, nums.end());
    }
};
// @lc code=end

