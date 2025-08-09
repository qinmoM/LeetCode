/*
 * @lc app=leetcode id=859 lang=cpp
 *
 * [859] Buddy Strings
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool buddyStrings(string s, string goal)
    {
        if (s.length() != goal.length())
        {
            return false;
        }
        vector<int> indexs;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] != goal[i])
            {
                indexs.push_back(i);
            }
        }
        if (2 != indexs.size() && 0 != indexs.size())
        {
            return false;
        }
        if (0 == indexs.size())
        {
            for (int i = 1; i < s.length(); ++i)
            {
                for (int j = 0; j < i; ++j)
                {
                    if (s[i] == s[j])
                    {
                        return true;
                    }
                }
            }
            return false;
        }
        if (goal[indexs[0]] == s[indexs[1]] && goal[indexs[1]] == s[indexs[0]])
        {
            return true;
        }
        return false;
    }
};
// @lc code=end

