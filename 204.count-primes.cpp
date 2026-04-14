/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

// @lc code=start
#include <vector>

class Solution
{
public:
    int countPrimes(int n)
    {
        std::vector<char> vec(n, 0);

        int res = 0;
        for (int i = 2; i < n; ++i)
        {
            if (vec[i]) continue;

            ++res;
            for (long long j = static_cast<long long>(i) * i; j < n; j += i)
                vec[j] = 1;
        }

        return res;
    }
};
// @lc code=end

