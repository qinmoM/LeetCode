/*
 * @lc app=leetcode id=1035 lang=cpp
 *
 * [1035] Uncrossed Lines
 */

// @lc code=start
#include <vector>

using std::vector;

class Solution
{
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2)
    {
        std::vector<std::vector<int>> dp(nums1.size() + 1, std::vector<int>(nums2.size() + 1, 0));
        for (int i = 1; i <= nums1.size(); ++i)
        {
            for (int j = 1; j <= nums2.size(); ++j)
            {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[nums1.size()][nums2.size()];

        // std::unordered_map<int, std::vector<int>> hash;
        // for (int i = 0; i < nums2.size(); ++i)
        //     hash[nums2[i]].push_back(i);
        //
        // int result = 0;
        // dfs(result, 0, 0, 0, nums1, hash);
        // return result;
    }

    // void dfs(int& res, int temp, int curr1, int curr2, const vector<int>& nums1, const std::unordered_map<int, std::vector<int>> hash)
    // {
    //     res = std::max(res, temp);
    //     if (curr1 >= nums1.size()) return;
    //
    //     for (int i = curr1; i < nums1.size(); ++i)
    //     {
    //         auto it = hash.find(nums1[i]);
    //         if (it == hash.end()) continue;
    //         for (int j : it->second)
    //         {
    //             if (j < curr2)
    //                 continue;
    //
    //             dfs(res, temp + 1, i + 1, j + 1, nums1, hash);
    //         }
    //     }
    // }
};
// @lc code=end

