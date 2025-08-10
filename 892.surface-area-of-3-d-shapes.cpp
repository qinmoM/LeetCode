/*
 * @lc app=leetcode id=892 lang=cpp
 *
 * [892] Surface Area of 3D Shapes
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    int surfaceArea(vector<vector<int>>& grid)
    {
        int count = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (0 == grid[i][j])
                {
                    continue;
                }

                count += 2;

                if (0 == i)
                {
                    count += grid[i][j];
                }
                else
                {
                    count += (grid[i][j] > grid[i - 1][j] ? grid[i][j] - grid[i - 1][j] : 0);
                }

                if (0 == j)
                {
                    count += grid[i][j];
                }
                else
                {
                    count += (grid[i][j] > grid[i][j - 1] ? grid[i][j] - grid[i][j - 1] : 0);
                }

                if (grid.size() - 1 == i)
                {
                    count += grid[i][j];
                }
                else
                {
                    count += (grid[i][j] > grid[i + 1][j] ? grid[i][j] - grid[i + 1][j] : 0);
                }

                if (grid[0].size() - 1 == j)
                {
                    count += grid[i][j];
                }
                else
                {
                    count += (grid[i][j] > grid[i][j + 1] ? grid[i][j] - grid[i][j + 1] : 0);
                }
            }
        }
        return count;
    }
};
// @lc code=end

