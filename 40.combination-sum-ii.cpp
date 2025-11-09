/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
#include <vector>
#include <algorithm>

using std::vector;

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        std::vector<std::vector<int>> result;
        std::sort(candidates.begin(), candidates.end());
        recursion(result, candidates, target, {}, 0, -1);
        return result;
    }

    void recursion(std::vector<std::vector<int>>& result, const vector<int>& candidates,
        const int target, std::vector<int> vec, int val, int curr)
    {
        for (int i = curr + 1; i < candidates.size(); )
        {
            int temp = candidates[i] + val;
            if (temp > target)
            {
                break;
            }
            vec.push_back(candidates[i]);
            if (temp == target)
            {
                result.push_back(vec);
                break;
            }
            recursion(result, candidates, target, vec, temp, i);
            vec.pop_back();
            do { i++; } while (i < candidates.size() && candidates[i - 1] == candidates[i]);
        }
    }

};
// @lc code=end

