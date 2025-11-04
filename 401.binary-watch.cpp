/*
 * @lc app=leetcode id=401 lang=cpp
 *
 * [401] Binary Watch
 */

// @lc code=start
#include <string>
#include <vector>

using std::vector;
using std::string;

class Solution
{
public:
    vector<string> readBinaryWatch(int turnedOn)
    {
        if (9 <= turnedOn)
        {
            return {};
        }
        std::vector<std::string> result;
        std::vector<int> table = { 1, 2, 4, 8, 16, 32, 1, 2, 4, 8 };
        recursion(table, result, turnedOn, 0, 0, 0);
        return result;
    }

    void recursion(const std::vector<int>& table, std::vector<string>& result, int level, int hour, int minute, int last)
    {
        if (0 == level)
        {
            if (range(hour, minute))
            {
                result.push_back(std::to_string(hour) + ":" + (minute >= 10 ? "" : "0") + std::to_string(minute));
            }
            return;
        }

        for (int i = last; i < table.size(); ++i)
        {
            if (i > 5)
            {
                recursion(table, result, level - 1, hour + table[i], minute, i + 1);
            }
            else
            {
                recursion(table, result, level - 1, hour, minute + table[i], i + 1);
            }
        }
    }

    bool range(int hour, int minute)
    {
        return (hour >= 0 && hour < 12) && (minute >= 0 && minute < 60);
    }

};
// @lc code=end

