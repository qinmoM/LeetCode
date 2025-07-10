/*
 * @lc app=leetcode id=561 lang=cpp
 *
 * [561] Array Partition
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int arrayPairSum(vector<int>& nums)
    {
        int size = static_cast<int>(nums.size());
        sort(nums.begin(), nums.end());
        int result = 0;
        for (int i = 0; i < size; i += 2)
        {
            result += nums[i];
        }
        return result;
    }
};
// @lc code=end

