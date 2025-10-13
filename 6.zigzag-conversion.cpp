/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
#include <string>
#include <vector>

using std::string;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (1 == numRows || numRows >= s.length())
        {
            return s;
        }
        std::vector<std::string> target(numRows);
        int index = 0;
        int dir = 1;
        for (char c : s)
        {
            target[index].push_back(c);
            if (0 == index)
            {
                dir = 1;
            }
            else if (numRows - 1 == index)
            {
                dir = -1;
            }
            index += dir;
        }
        std::string result;
        result.reserve(s.length());
        for (const std::string& s : target)
        {
            result += s;
        }
        return result;
    }
};
// @lc code=end

