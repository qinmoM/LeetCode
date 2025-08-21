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
        int bits = -1;
        while (n >> ++bits);
        return n ? ~n & ((1 << bits) - 1) : 1;
    }
};
// @lc code=end

