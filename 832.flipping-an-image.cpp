/*
 * @lc app=leetcode id=832 lang=cpp
 *
 * [832] Flipping an Image
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image)
    {
        for (std::vector<int>& vec : image)
        {
            std::reverse(vec.begin(), vec.end());
            for (int& i : vec)
            {
                i = !i;
            }
        }
        return image;
    }
};
// @lc code=end

