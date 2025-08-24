/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        int candidate = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (candidate != nums[i])
            {
                --count;
            }
            else
            {
                ++count;
            }

            if (!count)
            {
                candidate = nums[i];
                count = 1;
            }
        }
        return candidate;
    }
};
// @lc code=end

