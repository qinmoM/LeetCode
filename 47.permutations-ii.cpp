/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
#include <vector>
#include <algorithm>

using std::vector;

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result(1, nums);
        recursion(result, nums, 0);
        return result;
    }

    void recursion(std::vector<std::vector<int>>& result, vector<int>& nums, int exchanged)
    {
        if (exchanged == nums.size())
            return;

        int i = exchanged;
        do { ++i; } while(i < nums.size() && nums[exchanged] == nums[i]);
        while (i < nums.size())
        {
            std::swap(nums[exchanged], nums[i]);
            result.push_back(nums);
            recursion(result, nums, exchanged + 1);
            std::swap(nums[exchanged], nums[i]);

            do { ++i; } while(i < nums.size() && nums[exchanged] == nums[i]);
        }

        recursion(result, nums, exchanged + 1);
    }

};
// @lc code=end

