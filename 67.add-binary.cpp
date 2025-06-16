/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start

#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int carry = 0;
        int aIndex = a.length() - 1;
        int bIndex = b.length() - 1;
        for (; carry || 0 <= aIndex || 0 <= bIndex; aIndex--, bIndex--)
        {
            int temp = carry + (aIndex >= 0 ? a[aIndex] - '0' : 0) + (bIndex >= 0 ? b[bIndex] - '0' : 0);
            carry = temp / 2;
            result = static_cast<char>(temp % 2 + '0') + result;
        }
        return result;
    }
};
// @lc code=end

