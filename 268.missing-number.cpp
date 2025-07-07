/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    int missingNumber(vector<int>& nums)
    {
        int size = nums.size();
        int all = (1 + size) * size / 2;
        for (int i = 0; i < size; i++)
        {
            all -= nums[i];
        }
        return all;
    }
};
// @lc code=end

