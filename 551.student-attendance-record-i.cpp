/*
 * @lc app=leetcode id=551 lang=cpp
 *
 * [551] Student Attendance Record I
 */

// @lc code=start
#include <string>

using namespace std;

class Solution
{
public:
    bool checkRecord(string s)
    {
        int countA = 0;
        int countL = 0;
        for (char c : s)
        {
            if (c == 'L')
            {
                if (++countL > 2)
                {
                    return false;
                }
            }
            else
            {
                countL = 0;
                if (c == 'A' && ++countA > 1)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

