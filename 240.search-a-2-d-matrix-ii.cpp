/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
#include <vector>

using std::vector;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if (target == matrix[i][j])
                    return true;
                else if (target < matrix[i][j])
                    break;
            }
        }

        return false;
    }
};
// @lc code=end

