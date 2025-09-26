/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution
{
public:
    int fib(int n)
    {
        if (1 == n || 0 == n)
        {
            return n;
        }

        return fib(n - 1) + fib(n - 2);
    }
};
// @lc code=end

