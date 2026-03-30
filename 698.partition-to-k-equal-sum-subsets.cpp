/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 */

// @lc code=start
#include <vector>
#include <algorithm>

using std::vector;

class Solution
{
public:
    bool canPartitionKSubsets(vector<int>& nums, int k)
    {
        int all = 0;
        for (int i : nums)
            all += i;

        if (all % k) return false;
        all /= k;

        std::sort(nums.rbegin(), nums.rend());
        if (nums[0] > all) return false;

        std::vector<int> vec(k, 0);
        return backtrack(vec, nums, 0, all);
    }

    bool backtrack(std::vector<int>& vec, const std::vector<int>& nums, int index, int target)
    {
        if (index == nums.size()) return true;

        for (int i = 0; i < vec.size(); ++i)
        {
            if (vec[i] + nums[index] > target || i > 0 && vec[i - 1] == vec[i]) continue;

            vec[i] += nums[index];
            if (backtrack(vec, nums, index + 1, target)) return true;
            vec[i] -= nums[index];
        }
        return false;
    }
};
// @lc code=end

