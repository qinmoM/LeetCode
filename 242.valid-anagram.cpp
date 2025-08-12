/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }
        unordered_map<char, int> Hash;
        for (char c : s)
        {
            ++Hash[c];
        }
        for (char c : t)
        {
            if (--Hash[c] < 0)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

