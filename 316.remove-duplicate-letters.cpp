/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::string;

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        std::unordered_map<char, int> nums;
        for (char c : s)
            ++nums[c];

        std::string res;
        std::unordered_set<char> hash;
        for (char c : s)
        {
            --nums[c];

            if (!res.empty() && hash.find(c) != hash.end()) continue;
            hash.insert(c);

            if (res.empty() || res.back() < c)
            {
                res.push_back(c);
                continue;
            }

            hash.insert(c);

            while (res.size() && res.back() >= c && nums[res.back()])
            {
                hash.erase(res.back());
                res.pop_back();
            }
            res.push_back(c);
            hash.insert(c);
        }

        return res;

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

