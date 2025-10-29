/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

// @lc code=start
#include <vector>
#include <algorithm>

using std::vector;

class Solution
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        int result = 0;
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int sizeG = g.size();
        int sizeS = s.size();
        int gIndex = 0;
        int sIndex = 0;
        while (gIndex < sizeG && sIndex < sizeS)
        {
            if (s[sIndex] >= g[gIndex])
            {
                ++gIndex;
                ++result;
            }
            ++sIndex;
        }
        return result;

        // std::sort(s.begin(), s.end());
        // int result = 0;
        // for (int i = 0; i < s.size(); ++i)
        // {
        //     for (int j = 0; j < g.size(); ++j)
        //     {
        //         if (g[j] != -1 && s[i] >= g[j])
        //         {
        //             g[j] = -1;
        //             ++result;
        //             break;
        //         }
        //     }
        // }
        // return result;
    }
};
// @lc code=end

