/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

// @lc code=start
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        std::unordered_map<char, int> hash;
        int result = 0;
        int numOdd = 0;
        for (char i : s)
        {
            if (hash.find(i) == hash.end())
            {
                hash[i] = 1;
                ++numOdd;
            }
            else
            {
                ++hash[i];
                if (!(hash[i] & 1))
                {
                    result += 2;
                    --numOdd;
                }
                else
                {
                    ++numOdd;
                }
            }
        }
        return result + (numOdd ? 1 : 0);
    }
};
// @lc code=end

