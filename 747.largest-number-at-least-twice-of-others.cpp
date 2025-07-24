/*
 * @lc app=leetcode id=747 lang=cpp
 *
 * [747] Largest Number At Least Twice of Others
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    int dominantIndex(vector<int>& nums)
    {
        int size = nums.size();
        int max = (nums[0] >= nums[1] ? 0 : 1);
        int second = (max ? 0 : 1);
        for (int i = 2; i < size; i++)
        {
            int temp = nums[i];
            if (temp > nums[max])
            {
                second = max;
                max = i;
            }
            else if (temp > nums[second])
            {
                second = i;
            }
        }
        return (nums[max] >= nums[second] * 2 ? max : -1);
    }
};
// @lc code=end

