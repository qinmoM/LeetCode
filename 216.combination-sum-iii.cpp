/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start

#include <vector>

using std::vector;

class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        if (n > 45)
        {
            return {};
        }
        std::vector<std::vector<int>> result;
        std::vector<int> vec;
        recursion(result, k, n, vec);
        return result;
    }

    void recursion(std::vector<std::vector<int>>& result, int k, int n, std::vector<int>& vec)
    {
        if (!k)
        {
            if (!n)
            {
                result.push_back(vec);
            }
            return;
        }
        for (int i = (vec.size() > 0 ? vec[vec.size() - 1] : 0) + 1; i <= 9; ++i)
        {
            vec.push_back(i);
            recursion(result, k - 1, n - i, vec);
            vec.pop_back();
        }
    }

};
// @lc code=end

