/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
#include <iostream>
#include <limits.h>

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (INT_MIN == dividend)
        {
            if (-1 == divisor)
                return INT_MAX;
            if (1 == divisor)
                return INT_MIN;
        }
        bool isNegative = (dividend > 0) ^ (divisor > 0);
        long long Dividend = std::abs(static_cast<long long>(dividend));
        long long Divisor  = std::abs(static_cast<long long>(divisor));
        long long result = 0;
        while (Dividend >= Divisor)
        {
            long long tempDivisor = Divisor;
            int level = 1;
            while (Dividend >= (tempDivisor << 1))
            {
                tempDivisor <<= 1;
                level <<= 1;
            }
            result += level;
            Dividend -= tempDivisor;
        }
        if (isNegative)
        {
            result = -result;
        }
        if (INT_MAX <= result)
        {
            return INT_MAX;
        }
        if (INT_MIN >= result)
        {
            return INT_MIN;
        }
        return result;

        // bool isNegative = ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0));
        // dividend = std::abs(dividend);
        // divisor = std::abs(divisor);
        // int level = 0;
        // while ((dividend -= divisor) >= 0) ++level;
        // return isNegative ? -level : level;
    }
};
// @lc code=end

