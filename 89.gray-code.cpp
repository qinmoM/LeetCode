/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */

// @lc code=start
#include <vector>

using std::vector;

class Solution
{
public:
    vector<int> grayCode(int n)
    {
        std::vector<int> result = { 0, 1 };
        recursion(result, 1, n);
        return result;
    }

    void recursion(std::vector<int>& result, int gap, int n)
    {
        if (1 == n)
        {
            return;
        }

        gap *= 2;
        for (int i = result.size() - 1; i >= 0; --i)
        {
            result.push_back(result[i] + gap);
        }

        recursion(result, gap, n - 1);
    }

};
// @lc code=end

