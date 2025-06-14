/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        int middle = 0;
        while (true)
        {
            if (left == right - 1)
            {
                if (nums[left] >= target)
                {
                    return left;
                }
                else
                {
                    return right;
                }
            }
            middle = (right + left) / 2;
            if (left == right)
            {
                return middle;
            }
            int temp = nums[middle];
            if (temp == target)
            {
                return middle;
            }
            if (temp < target)
            {
                left = middle;
            }
            if (temp > target)
            {
                right = middle;
            }
        }
    }
};
// @lc code=end

