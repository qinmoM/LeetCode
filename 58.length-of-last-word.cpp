/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start

#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int all = s.length();
        int count = 0;
        for (int i = all; i > 0; i--)
        {
            if (' ' != s[i - 1])
            {
                all = i;
                break;
            }
        }
        for (int i = all; i > 0; i--)
        {
            if(' ' == s[i - 1])
            {
                break;
            }
            else
            {
                count++;
            }
        }
        return count;
    }
};
// @lc code=end

