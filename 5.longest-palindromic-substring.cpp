/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start

#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int count = s.length();
        string result;
        int all = 1;
        int index = 0;
            // odd
        result = s[0];
        for (int i = 1; i < count; i++)
        {
            int offset = 1;
            while (i - offset >= 0 && i + offset < count)
            {
                if (s[i - offset] == s[i + offset])
                {
                    offset++;
                    index = i - offset + 1;
                }
                else
                {
                    index = i - offset + 1;
                    break;
                }
            }
            offset = offset * 2 - 1;
            if (offset > all)
            {
                all = offset;
                result = "";
                for (int i = 0; i < offset; i++)
                {
                    result += s[index + i];
                }
            }
        }
            // even
        if (all <= 1 && s[0] == s[1])
        {
            all = 2;
            result = "";
            result += s[0];
            result += s[1];
        }
        for (int i = 0; i < count; i++)
        {
            int offset = 1;
            if (s[i] == s[i + 1])
            {
                while (i - offset >= 0 && i + 1 + offset < count)
                {
                    if (s[i - offset] == s[i + 1 + offset])
                    {
                        offset++;
                        index = i -offset + 1;
                    }
                    else
                    {
                        index = i - offset + 1;
                        break;
                    }
                }
            }
            else
            {
                continue;
            }
            offset = offset * 2;
            if (all < offset)
            {
                all = offset;
                result = "";
                for (int i = 0; i < offset; i++)
                {
                    result += s[index + i];
                }
            }
        }
        return result;
    }
};
// @lc code=end

