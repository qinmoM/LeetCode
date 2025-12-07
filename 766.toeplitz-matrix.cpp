/*
 * @lc app=leetcode id=766 lang=cpp
 *
 * [766] Toeplitz Matrix
 */

// @lc code=start
#include <vector>

using std::vector;

class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix)
    {
        std::vector<int> standard(matrix[0]);
        for (int i = 1; i < matrix.size(); ++i)
        {
            for (int j = 1; j < matrix[0].size(); ++j)
            {
                if (matrix[i][j] != standard[j - 1]) return false;
            }
            standard = matrix[i];
        }
        return true;
    }
};
// @lc code=end

