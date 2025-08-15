/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        std::unordered_map<char, int> hash;
        for (char c : s)
        {
            if (hash.find(c) == hash.end())
            {
                hash[c] = 1;
            }
            else
            {
                ++hash[c];
            }
        }

        for (int i = 0; i < s.length(); ++i)
        {
            if (hash[s[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

