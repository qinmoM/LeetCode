/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if (2 >= n)
        {
            return n;
        }
        int temp1 = 1;
        int temp2 = 2;
        int temp = 0;
        for (int i = 3; i <= n; i++)
        {
            temp = temp1 + temp2;
            temp1 = temp2;
            temp2 = temp;
        }
        return temp;
    }
};
// @lc code=end

