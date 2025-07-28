/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int>& nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            if (nums[left] & 1)
            {
                if (nums[right] & 1)
                {
                    right--;
                }
                else
                {
                    std::swap(nums[left], nums[right]);
                }
            }
            else
            {
                left++;
            }
        }
        return nums;
    }
};
// @lc code=end

