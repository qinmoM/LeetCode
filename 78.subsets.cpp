/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
#include <vector>

using std::vector;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        std::vector<std::vector<int>> result(1, nums);
        std::vector<int> vec;
        for (int i = 0; i < nums.size(); ++i)
        {
            recursion(result, nums, i, vec, 0);
        }
        return result;
    }

    void recursion(std::vector<std::vector<int>>& result, const std::vector<int>& nums, int count, vector<int>& vec, int index)
    {
        if (0 == count)
        {
            return result.push_back(vec);
        }

        for (int i = index; i < nums.size(); ++i)
        {
            vec.push_back(nums[i]);
            recursion(result, nums, count - 1, vec, i + 1);
            vec.pop_back();
        }
    }

};
// @lc code=end

