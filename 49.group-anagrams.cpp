/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::string;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        std::unordered_map<std::string, std::vector<std::string>> hash;
        for (const std::string& s : strs)
        {
            std::string temp = s;
            std::sort(temp.begin(), temp.end());
            hash[temp].push_back(s);
        }

        std::vector<std::vector<std::string>> res;
        for (const auto& [_, vec] : hash)
            res.push_back(std::move(vec));

        return res;
    }
};
// @lc code=end

