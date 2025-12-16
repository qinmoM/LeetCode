/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
#include <vector>

using std::vector;

class Solution
{
public:
    void sortColors(vector<int>& nums)
    {
        int left = 0;
        while (left < nums.size() && 0 == nums[left]) ++left;
        int mid = left;
        int right = nums.size() - 1;
        while (right >= 0 && 2 == nums[right]) --right;
        while (mid <= right)
        {
            if (0 == nums[mid])
            {
                std::swap(nums[mid], nums[left]);
                ++left;
                ++mid;
            }
            else if (2 == nums[mid])
            {
                std::swap(nums[mid], nums[right]);
                --right;
            }
            else ++mid;
        }

        // int curr = 0;
        // for (int i = 0; i < nums.size(); ++i)
        // {
        //     while (i < nums.size() && nums[i] == 0) ++i;
        //     curr = i + 1;
        //     while (curr < nums.size() && nums[i] != 0) ++curr;
        //     if (curr >= nums.size())
        //     {
        //         curr = i;
        //         break;
        //     }
        //     std::swap(nums[i], nums[curr]);
        // }
        // for (int i = curr; i < nums.size(); ++i)
        // {
        //     while (i < nums.size() && nums[i] == 1) ++i;
        //     curr = i + 1;
        //     while (curr < nums.size() && nums[i] != 1) ++curr;
        //     if (curr >= nums.size()) break;
        //     std::swap(nums[i], nums[curr]);
        // }
    }
};
// @lc code=end

