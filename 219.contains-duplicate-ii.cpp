/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                if (size > j + i && nums[i] == nums[j + i])
                {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

