/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
#include <string>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int left = -1;
        int right = s.length();
        while (left < right)
        {
            while (left < right && !std::isalnum(s[++left]));
            while (left < right && !std::isalnum(s[--right]));

            if (std::tolower(s[left]) != std::tolower(s[right]))
            {
                return false;
            }
        }
        return true;

        // {
        //     std::string temp;
        //     for (char c : s)
        //     {
        //         if (std::isalnum(c))
        //         {
        //             temp += tolower(c);
        //         }
        //     }
        //     s.swap(temp);
        // }
        //
        // int left = 0;
        // int right = s.length() - 1;
        // while (right > left)
        // {
        //     if (s[left++] != s[right--])
        //     {
        //         return false;
        //     }
        // }
        //
        // return true;
    }
};
// @lc code=end

