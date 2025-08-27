/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
#include <string>

using namespace std;

class Solution
{
public:
    string reverseVowels(string s)
    {
        int left = -1;
        int right = s.length();
        while (true)
        {
            while (left < right && !isSymbol(s[++left]));
            while (left < right && !isSymbol(s[--right]));
            if (left < right)
            {
                std::swap(s[left], s[right]);
            }
            else
            {
                break;
            }
        }
        return s;
    }

    bool isSymbol(char c)
    {
        char temp = tolower(c);
        return 'a' == temp || 'e' == temp || 'i' == temp || 'o' == temp || 'u' == temp;
    }

};
// @lc code=end

