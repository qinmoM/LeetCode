/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
#include <vector>

using std::vector;

class Solution
{
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        std::vector<std::vector<int>> result;
        recursion(result, nums, 0);
        return result;
    }

    void recursion(std::vector<std::vector<int>>& result, vector<int>& vec, int fixed)
    {
        if (fixed == vec.size())
        {
            result.push_back(vec);
        }

        for (int i = fixed; i < vec.size(); ++i)
        {
            std::swap(vec[i], vec[fixed]);
            recursion(result, vec, fixed + 1);
            std::swap(vec[i], vec[fixed]);
        }
    }

};
// @lc code=end

