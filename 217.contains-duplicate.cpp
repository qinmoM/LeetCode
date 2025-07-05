/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        int size = nums.size();
        std::sort(nums.begin(), nums.end());
        for (int i = 1; i < size; i++)
        {
            if (nums[i] == nums[i - 1])
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

