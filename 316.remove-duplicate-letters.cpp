/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <vector>

using std::string;

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        ;

        // std::unordered_map<char, int> hash(26);
        // std::string res;
        // int last = 0;
        //
        // for (int i = 0; i < s.size(); ++i)
        // {
        //     auto it = hash.find(s[i]);
        //     if (it == hash.end())
        //     {
        //         res += s[i];
        //         hash[s[i]] = i;
        //     }
        //     else
        //     {
        //         std::string temp = res.substr(0, it->second - last) + res.substr(it->second - last + 1, res.size() - 1 - it->second + last) + s[i];
        //         bool is = res > temp;
        //         if (is)
        //         {
        //             res = temp;
        //             hash[s[i]] = i;
        //         }
        //         ++last;
        //     }
        // }
        //
        // return res;
    }
};
// @lc code=end

