/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
#include <vector>

using namespace std;
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;
        vector<int> last;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> curr;
            for (int j = 0; j <= i; j++)
            {
                if (0 == j || i == j)
                {
                    curr.push_back(1);
                }
                else
                {
                    curr.push_back(last[j - 1] + last[j]);
                }
            }
            result.push_back(curr);
            last = curr;
        }
        return result;
    }
};
// @lc code=end

