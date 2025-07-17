/*
 * @lc app=leetcode id=628 lang=cpp
 *
 * [628] Maximum Product of Three Numbers
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maximumProduct(vector<int>& nums)
    {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        int product1 = nums[size - 1] * nums[size - 2] * nums[size - 3];
        int product2 = nums[size - 1] * nums[0] * nums[1];
        return product1 > product2 ? product1 : product2;
    }
};
// @lc code=end

