/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int count = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            std::unordered_set<char> hash;
            int index = i;
            hash.insert(s[index]);
            while (++index < s.length())
            {
                if (hash.find(s[index]) != hash.end())
                {
                    break;
                }
                else
                {
                    hash.insert(s[index]);
                }
            }
            count = std::max(count, static_cast<int>(hash.size()));
        }
        return count;
    }
};
// @lc code=end

