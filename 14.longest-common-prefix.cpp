/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int all = strs[0].length();
        string s = "";
        int strSize = strs.size();
        for (int j = 0; j < strSize; j++)
        {
            all = min(all, strs[j].length());
        }
        for (int j = 0; j < all; j++)
        {
            char temp = strs[0][j];
            for (int i = 0; i < strSize; i++)
            {
                if (strs[i][j] != temp)
                {
                    return s;
                }
            }
            s += temp;
        }
        return s;
    }

    inline int min(int origin, int now)
    {
        if (now < origin)
        {
            return now;
        }
        return origin;
    }
};
// @lc code=end

