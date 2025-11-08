/*
 * @lc app=leetcode id=917 lang=cpp
 *
 * [917] Reverse Only Letters
 */

// @lc code=start
#include <string>

using std::string;

class Solution
{
public:
    string reverseOnlyLetters(string s)
    {
        int left = 0;
        int right = s.length() - 1;
        while (left < right)
        {
            while (left < right && !letter(s[left])) ++left;
            while (left < right && !letter(s[right])) --right;
            if (left < right)
            {
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                ++left;
                --right;
            }
        }
        return s;
    }

    bool letter(char a)
    {
        return (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z');
    }

};
// @lc code=end

