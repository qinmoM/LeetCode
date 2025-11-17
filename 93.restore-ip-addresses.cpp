/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        if (s.length() < 4 || s.length() > 12)
        {
            return {};
        }
        std::vector<std::string> result;
        dep(result, s, 0, {});
        return result;
    }

    void dep(std::vector<std::string>& result, std::string& s, int index, std::vector<string> t)
    {
        if (t.size() == 4)
        {
            if (index == s.length())
            {
                result.push_back(t[0] + "." + t[1] + "." + t[2] + "." + t[3]);
            }
            return;
        }

        for (int i = 1; i < 4; ++i)
        {
            if (index + i > s.length()) return;
            string str = s.substr(index, i);
            if (1 < i && '0' == str[0]) return;
            if (std::stoi(str) > 255) return;
            t.push_back(str);
            dep(result, s, index + i, t);
            t.pop_back();
        }
    }

};
// @lc code=end

