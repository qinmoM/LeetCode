/*
 * @lc app=leetcode id=500 lang=cpp
 *
 * [500] Keyboard Row
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<string> findWords(vector<string>& words)
    {
        vector<string> result;
        std::unordered_map<char, int> hash;
        std::string temp = "qwertyuiopQWERTYUIOP";
        for (char c : temp)
        {
            hash[c] = 1;
        }
        temp = "asdfghjklASDFGHJKL";
        for (char c : temp)
        {
            hash[c] = 2;
        }
        temp = "zxcvbnmZXCVBNM";
        for (char c : temp)
        {
            hash[c] = 3;
        }

        for (string s : words)
        {
            if (s.length() == 0)
            {
                continue;
            }
            bool isKind = true;
            int stand = hash[s[0]];
            for (char c : s)
            {
                if (hash[c] != stand)
                {
                    isKind = false;
                }
                if (!isKind)
                {
                    break
                }
            }
            if (isKind)
            {
                result.push_back(s);
            }
        }
        return result;
    }
};
// @lc code=end

