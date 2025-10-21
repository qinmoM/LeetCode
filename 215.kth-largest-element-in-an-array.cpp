/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
#include <vector>

using std::vector;

class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        return quick(nums, 0, nums.size() - 1, k - 1);
    }

    int quick(std::vector<int>& nums, int left, int right, const int& k)
    {
        int leftTemp = left;
        int rightTemp = right;
        while (leftTemp < rightTemp)
        {
            while (leftTemp < rightTemp && nums[leftTemp] >= nums[rightTemp])
            {
                --rightTemp;
            }
            if (leftTemp < rightTemp)
            {
                std::swap(nums[leftTemp], nums[rightTemp]);
                ++leftTemp;
            }
            while (leftTemp < rightTemp && nums[leftTemp] >= nums[rightTemp])
            {
                ++leftTemp;
            }
            if (leftTemp < rightTemp)
            {
                std::swap(nums[leftTemp], nums[rightTemp]);
                --rightTemp;
            }
        }
        if (k == leftTemp)
        {
            return nums[k];
        }
        else if (k < leftTemp)
        {
            return quick(nums, left, leftTemp - 1, k);
        }
        else
        {
            return quick(nums, leftTemp + 1, right, k);
        }
    }

};
// @lc code=end

