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
        while (num / 10)
        {
            int temp = num;
            int all = 0;
            do { all += temp % 10; } while (temp /= 10);
            num = all;
        }
        return num;
    }
};
// @lc code=end

