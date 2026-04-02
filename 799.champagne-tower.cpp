/*
 * @lc app=leetcode id=799 lang=cpp
 *
 * [799] Champagne Tower
 */

// @lc code=start
#include <vector>

using std::vector;

class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        std::vector<std::vector<double>> dp(101, std::vector<double>(101, 0.0));
        dp[0][0] = poured;

        for (int i = 0; i <= query_row; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                if (dp[i][j] > 1.0)
                {
                    double temp = (dp[i][j] - 1.0) / 2;
                    dp[i + 1][j] += temp;
                    dp[i + 1][j + 1] += temp;
                }
            }
        }
        return std::min(1.0, dp[query_row][query_glass]);
    }
};
// @lc code=end

