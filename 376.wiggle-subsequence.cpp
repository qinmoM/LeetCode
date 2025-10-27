/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */

// @lc code=start
#include <vector>

using std::vector;

class Solution
{
public:
    int wiggleMaxLength(vector<int>& nums)
    {
        int size = nums.size();
        int i = 1;
        while (i < size && nums[i] == nums[0]) ++i;

        if (i == size)
            return 1;

        int result = 2;
        bool ascend = nums[0] < nums[i];
        for (; i < size; ++i)
        {
            if ((ascend && nums[i - 1] > nums[i]) || (!ascend && nums[i - 1] < nums[i]))
            {
                ascend = !ascend;
                ++result;
            }
        }
        return result;

        // int size = nums.size();
        // if (size == 1)
        // {
        //     return 1;
        // }
        // bool ascend = nums[0] < nums[1];
        // int result = 2;
        // int temp = 2;
        // for (int i = 2; i < size; ++i)
        // {
        //     if ((ascend && nums[i - 1] > nums[i]) || (!ascend && nums[i - 1] < nums[i]))
        //     {
        //         ++temp;
        //         ascend = !ascend;
        //         continue;
        //     }
        //     temp = 2;
        //     result = std::max(result, temp);
        // }
        // return result;
    }
};
// @lc code=end

