/*
 * @lc app=leetcode id=771 lang=cpp
 *
 * [771] Jewels and Stones
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        std::unordered_map<char, int> hash;
        for (char c : jewels)
        {
            hash[c] = 0;
        }

        for (char c : stones)
        {
            if (hash.find(c) != hash.end())
            {
                ++hash[c];
            }
        }

        int result = 0;
        for (auto& [_, second] : hash)
        {
            result += second;
        }
        return result;
    }
};
// @lc code=end

