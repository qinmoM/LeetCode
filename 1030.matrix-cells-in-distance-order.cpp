/*
 * @lc app=leetcode id=1030 lang=cpp
 *
 * [1030] Matrix Cells in Distance Order
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter)
    {
        std::vector<std::vector<int>> result;
        std::multimap<int, std::vector<int>> multimap;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                multimap.insert( { std::abs(rCenter - i) + std::abs(cCenter - j), { i, j } });
            }
        }
        for (std::pair<int, std::vector<int>> pair : multimap)
        {
            result.push_back(pair.second);
        }
        return result;
    }
};
// @lc code=end

