/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
#include <vector>

using std::vector;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        std::vector<std::vector<int>> result;
        std::vector<int> temp;
        combination(result, candidates, temp, target, 0, 0);
        return result;
    }

    void combination(std::vector<std::vector<int>>& result, const std::vector<int>& candidates
        , std::vector<int>& temp, const int target, int sum, int currIndex)
    {
        if (sum == target)
        {
            result.push_back(temp);
            return;
        }

        for (int i = currIndex; i < candidates.size(); ++i)
        {
            int t = candidates[i] + sum;
            if (t > target) continue;
            temp.push_back(candidates[i]);
            combination(result, candidates, temp, target, t, i);
            temp.pop_back();

        }
    }

};
// @lc code=end

