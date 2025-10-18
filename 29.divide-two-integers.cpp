/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
#include <iostream>

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        bool isNegative = ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0));
        dividend = std::abs(dividend);
        divisor = std::abs(divisor);
        int level = 0;
        while ((dividend -= divisor) >= 0) ++level;
        return isNegative ? -level : level;
    }
};
// @lc code=end

