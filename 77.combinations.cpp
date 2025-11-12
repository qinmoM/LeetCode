/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
#include <vector>

using std::vector;

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        std::vector<std::vector<int>> result;
        std::vector<int> vec;
        recursion(result, n, k, 1, vec);
        return result;
    }

    void recursion(std::vector<std::vector<int>>& result, const int n, const int k, int index, std::vector<int>& vec)
    {
        if (k == vec.size())
        {
            result.push_back(vec);
            return;
        }

        for (int i = index; i + (k - vec.size()) <= n + 1; ++i)
        {
            vec.push_back(i);
            recursion(result, n, k, i + 1, vec);
            vec.pop_back();
        }
    }

};
// @lc code=end

