/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> result;
        vector<int> temp;
        for (int i = 0; i <= rowIndex; i++)
        {
            result.clear();
            for (int j = 0; j <= i; j++)
            {
                if (0 == j || i == j)
                {
                    result.push_back(1);
                }
                else
                {
                    result.push_back(temp[j - 1] + temp[j]);
                }
            }
            temp = result;
        }
        return result;
    }
};
// @lc code=end

