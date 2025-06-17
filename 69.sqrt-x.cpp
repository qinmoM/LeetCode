/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int temp = 0;
        for (int i = 10000; static_cast<long long>(temp + i) * (temp + i) <= x; )
        {
            temp += i;
        }
        for (int i = 1000; static_cast<long long>(temp + i) * (temp + i) <= x; )
        {
            temp += i;
        }
        for (int i = 100; static_cast<long long>(temp + i) * (temp + i) <= x; )
        {
            temp += i;
        }
        for (int i = 10; static_cast<long long>(temp + i) * (temp + i) <= x; )
        {
            temp += i;
        }
        for (int i = 1; static_cast<long long>(temp + i) * (temp + i) <= x; )
        {
            temp += i;
        }
        return temp;
    }
};
// @lc code=end

