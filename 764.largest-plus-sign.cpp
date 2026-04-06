/*
 * @lc app=leetcode id=764 lang=cpp
 *
 * [764] Largest Plus Sign
 */

// @lc code=start
#include <vector>
#include <limits.h>
#include <unordered_set>

using std::vector;

class Solution
{
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines)
    {
        std::vector<std::vector<int>> res(n, std::vector<int>(n, INT_MAX));
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, INT_MAX));

        std::unordered_set<long long> hash;
        for (const std::vector<int>& vec : mines)
            hash.insert(tolong(vec[0], vec[1]));

        for (int i = 0; i < n; ++i)
        {
            int count = 0;
            for (int j = 0; j < n; ++j)
            {
                count = hash.find(tolong(i, j)) != hash.end() ? 0 : count + 1;
                dp[i][j] = count;
                res[i][j] = std::min(res[i][j], dp[i][j]);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            int count = 0;
            for (int j = n - 1; j >= 0; --j)
            {
                count = hash.find(tolong(i, j)) != hash.end() ? 0 : count + 1;
                dp[i][j] = count;
                res[i][j] = std::min(res[i][j], dp[i][j]);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            int count = 0;
            for (int j = 0; j < n; ++j)
            {
                count = hash.find(tolong(j, i)) != hash.end() ? 0 : count + 1;
                dp[j][i] = count;
                res[j][i] = std::min(res[j][i], dp[j][i]);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            int count = 0;
            for (int j = n - 1; j >= 0; --j)
            {
                count = hash.find(tolong(j, i)) != hash.end() ? 0 : count + 1;
                dp[j][i] = count;
                res[j][i] = std::min(res[j][i], dp[j][i]);
            }
        }

        int result = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                result = std::max(res[i][j], result);
        }
        return result;

        // std::unordered_set<long long> hash;
        // for (const std::vector<int>& vec : mines)
        //     hash.insert(tolong(vec[0], vec[1]));
        //
        // int result = 0;
        // for (int i = 0; i < n; ++i)
        // {
        //     for (int j = 0; j < n; ++j)
        //     {
        //         int min = INT_MAX;
        //         int temp = 0;
        //         for (int up = i; up >= 0 && hash.find(tolong(up, j)) == hash.end(); --up)
        //             temp += 1;
        //         min = std::min(min, temp);
        //
        //         temp = 0;
        //         for (int down = i; down < n && hash.find(tolong(down, j)) == hash.end(); ++down)
        //             temp += 1;
        //         min = std::min(min, temp);
        //
        //         temp = 0;
        //         for (int l = j; l >= 0 && hash.find(tolong(i, l)) == hash.end(); --l)
        //             temp += 1;
        //         min = std::min(min, temp);
        //
        //         temp = 0;
        //         for (int r = j; r < n && hash.find(tolong(i, r)) == hash.end(); ++r)
        //             temp += 1;
        //         min = std::min(min, temp);
        //
        //         result = std::max(result, min);
        //     }
        // }
        // return result;
    }

    long long tolong(int a, int b)
    {
        return (static_cast<long long>(a) << 32) | b;
    }
};
// @lc code=end

