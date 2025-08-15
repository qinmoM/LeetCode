/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }
        std::unordered_map<char, char> hashS;
        std::unordered_map<char, char> hashT;
        for (int i = 0; i < s.length(); ++i)
        {
            if (hashS.find(s[i]) == hashS.end())
            {
                if (hashT.find(t[i]) != hashT.end())
                {
                    return false;
                }
                hashS[s[i]] = t[i];
                hashT[t[i]] = s[i];
            }
            else
            {
                if (hashS[s[i]] != t[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

