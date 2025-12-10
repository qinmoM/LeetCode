/*
 * @lc app=leetcode id=1072 lang=cpp
 *
 * [1072] Flip Columns For Maximum Number of Equal Rows
 */

// @lc code=start
#include <vector>
#include <iostream>

using std::vector;

class Solution
{
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix)
    {
        int all = 0;
        std::vector<bool> same;
        recursion(matrix, all, 0, matrix.size(), same);
        return all;
    }

    void recursion(std::vector<std::vector<int>>& matrix, int& all, int col, int currAll, std::vector<bool>& same)
    {
        if (col >= matrix[0].size())
        {
            all = std::max(all, currAll);
            return;
        }

        if (all > currAll) return;
        same.push_back(true);
        recursion(matrix, all, col + 1, num(matrix, col, same), same);
        same.pop_back();
        same.push_back(false);
        recursion(matrix, all, col + 1, num(matrix, col, same), same);
        same.pop_back();
    }

    int num(const std::vector<std::vector<int>>& matrix, int col, const std::vector<bool>& same)
    {
        int num = 0;
        for (int i = 0; i < matrix.size(); ++i)
        {
            bool isSame = true;
            for (int j = 0; j < col; ++j)
            {
                bool left = same[j] ? matrix[i][j] : !matrix[i][j];
                bool right = same[j + 1] ? matrix[i][j + 1] : !matrix[i][j + 1];
                if (left == right)
                {
                    isSame = false;
                    break;
                }
            }
            if (isSame) ++num;
        }
        return num;
    }
};
// @lc code=end

