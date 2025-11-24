/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 */

// @lc code=start
class Solution
{
public:
    int addDigits(int num)
    {
        return (num % 9 == 0 ? (num == 0 ? 0 : 9) : num % 9);
    }
};
// @lc code=end

