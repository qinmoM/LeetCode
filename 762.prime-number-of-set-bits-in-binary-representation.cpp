/*
 * @lc app=leetcode id=762 lang=cpp
 *
 * [762] Prime Number of Set Bits in Binary Representation
 */

// @lc code=start
class Solution
{
public:
    int countPrimeSetBits(int left, int right)
    {
        static constexpr bool prime[21] = {
            false, false, true , true , false, true , false, true , false, false,
            false, true , false, true , false, false, false, true , false, true , false
        };
        int count = 0;
        for (int i = left; i <= right; ++i)
        {
            if (prime[__builtin_popcount(i)])
            {
                ++count;
            }
        }
        return count;
    }
};
// @lc code=end

