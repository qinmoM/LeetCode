/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
#include <vector>
#include <algorithm>

using std::vector;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; )
        {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                int temp = nums[left] + nums[right] + nums[i];
                if (!temp)
                {
                    result.push_back( { nums[i], nums[left], nums[right] } );
                }
                if (temp >= 0)
                {
                    do { --right; } while (left < right && nums[right] == nums[right + 1]);
                }
                if (temp <= 0)
                {
                    do { ++left; } while (left < right && nums[left] == nums[left - 1]);
                }
            }
            do { ++i; } while (i < nums.size() - 2 && nums[i] == nums[i - 1]);
        }
        return result;
    }
};
// @lc code=end

