/*
 * @lc app=leetcode id=1009 lang=cpp
 *
 * [1009] Complement of Base 10 Integer
 */

// @lc code=start
class Solution
{
public:
    int bitwiseComplement(int n) 
    {
        if (n == 0) return 1;
        int bits = 0;
        while (n >> bits++);
        return (~n) & ((1 << bits - 1) - 1);
    }
};
// @lc code=end

