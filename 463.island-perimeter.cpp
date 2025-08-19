/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    int islandPerimeter(vector<vector<int>>& grid)
    {
        int result = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j])
                {
                    if ((i == 0) || !grid[i - 1][j])
                    {
                        ++result;
                    }

                    if ((i == grid.size() - 1) || !grid[i + 1][j])
                    {
                        ++result;
                    }

                    if ((j == 0) || !grid[i][j - 1])
                    {
                        ++result;
                    }

                    if ((j == grid[0].size() - 1) || !grid[i][j + 1])
                    {
                        ++result;
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end

