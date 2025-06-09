/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
        {
            return false;
        }
        int count = 1;
        int temp = x;
        while (temp /= 10)
        {
            count++;
        }
        for (temp = count; temp > 1 && temp > (count - 1) / 2; temp--)
        {
            int left = x, right = x;
            for (int a = count - temp; a > 0; a--)
            {
                right /= 10;
            }
            right %= 10;
            for (int b = 0; b < temp - 1 ; b++)
            {
                left /= 10;
            }
            left %= 10;
            if (left != right)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

