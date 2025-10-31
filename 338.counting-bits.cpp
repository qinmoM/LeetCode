/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
#include <vector>

using std::vector;

class Solution
{
public:
    vector<int> countBits(int n)
    {
        std::vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            if (dp[i])
            {
                continue;
            }

            dp[i] = dp[i - 1] + 1;
            for (int j = i << 1; j <= n; j <<= 1)
            {
                dp[j] = dp[i];
            }
        }
        return dp;
    }
};
// @lc code=end

