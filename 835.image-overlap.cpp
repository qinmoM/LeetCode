/*
 * @lc app=leetcode id=835 lang=cpp
 *
 * [835] Image Overlap
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;

class Solution
{
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2)
    {
        int result = 0;
        for (int i = 0; i < img1.size(); ++i)
        {
            for (int j = 0; j < img1[0].size(); ++j)
            {
                if (result < (img1.size() - i) * (img1[0].size() - j))
                {
                    result = std::max(overlap(img1, img2, i, j), result);
                    result = std::max(overlap(img2, img1, i, j), result);
                }
            }
        }
        std::reverse(img1.begin(), img1.end());
        std::reverse(img2.begin(), img2.end());
        for (int i = 0; i < img1.size(); ++i)
        {
            for (int j = 0; j < img1[0].size(); ++j)
            {
                if (result < (img1.size() - i) * (img1[0].size() - j))
                {
                    result = std::max(overlap(img1, img2, i, j), result);
                    result = std::max(overlap(img2, img1, i, j), result);
                }
            }
        }
        return result;
    }

    int overlap(std::vector<std::vector<int>>& img1, std::vector<std::vector<int>>& img2, int offsetX, int offsetY)
    {
        int count = 0;
        int row = img1.size() - offsetX;
        int col = img1[0].size() - offsetY;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (img1[i + offsetX][j + offsetY] && img2[i][j]) ++count;
            }
        }
        return count;
    }

};
// @lc code=end

