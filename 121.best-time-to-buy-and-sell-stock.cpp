/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int size = prices.size();
        if (size < 2)
        {
            return 0;
        }
        int min = prices[0];
        int interest = 0;
        for (int i = 1; i < size; i++)
        {
            if (prices[i] < min)
            {
                min = prices[i];
            }
            else
            {
                interest = (prices[i] - min > interest ? prices[i] - min : interest);
            }
        }
        return interest;
    }
};
// @lc code=end

