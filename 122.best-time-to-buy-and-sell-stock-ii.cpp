/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
#include <vector>

using std::vector;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int result = 0;
        for (int i = 0; i < prices.size() - 1; ++i)
        {
            if (prices[i] < prices[i + 1])
            {
                result -= prices[i];
                result += prices[i + 1];
            }
        }
        return result;
    }
};
// @lc code=end

