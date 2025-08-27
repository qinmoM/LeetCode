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
        {
            std::string temp;
            for (char c : s)
            {
                if (std::isalnum(c))
                {
                    temp += tolower(c);
                }
            }
            s.swap(temp);
        }
        
        int left = 0;
        int right = s.length() - 1;
        while (right > left)
        {
            if (s[left++] != s[right--])
            {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

