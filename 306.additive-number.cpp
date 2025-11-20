/*
 * @lc app=leetcode id=306 lang=cpp
 *
 * [306] Additive Number
 */

// @lc code=start
#include <string>
#include <vector>

using std::string;

class Solution
{
public:
    bool isAdditiveNumber(string num)
    {
        std::vector<long long> vec;
        for (int i = 1; i < num.size(); ++i)
        {
            if ('0' == num[0] && i != 1) continue;
            vec.push_back(std::stoll(num.substr(0, i)));
            for (int j = 1; j + i < num.size(); ++j)
            {
                if ('0' == num[i] && j != 1) continue;
                vec.push_back(std::stoll(num.substr(i, j)));
                if (recursion(num.substr(i + j, num.size() - i - j), vec)) return true;
                vec.pop_back();
            }
            vec.pop_back();
        }
        return false;
    }

    bool recursion(std::string s, std::vector<long long> vec)
    {
        if (!s.size())
        {
            if (2 >= vec.size()) return false;
            return true;
        }
        if ('0' == s[0] && s.size() > 1) return false;
        long long num = vec[vec.size() - 1] + vec[vec.size() - 2];
        std::string temp = std::to_string(num);
        if (temp.size() > s.size() || s.substr(0, temp.size()) != std::to_string(num)) return false;
        vec.push_back(num);
        return recursion(s.substr(temp.size(), s.size() - temp.size()), vec);
    }

};
// @lc code=end

