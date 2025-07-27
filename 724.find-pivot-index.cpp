/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int>& nums)
    {
        int size = nums.size();
        int all = 0;
        int curr = 0;
        for (int i : nums)
        {
            all += i;
        }
        for (int i = 0; i < size; ++i)
        {
            if (all - nums[i] == curr * 2)
            {
                return i;
            }
            curr += nums[i];
        }
        return -1;
    }
};
// @lc code=end

