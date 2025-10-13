/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
#include <string>

using std::string;

class Solution
{
public:
    int myAtoi(string s)
    {
        int index = 0;
        while (index < s.length() && s[index] == ' ')
        {
            index += 1;
        }
        if (index >= s.length())
        {
            return 0;
        }
        s = s.substr(index);
        int temp = 1;
        if (s[0] > '9' || '0' > s[0])
        {
            if (s.length() == 1 || '-' != s[0] && '+' != s[0])
            {
                return 0;
            }
            if ('-' == s[0])
            {
                temp = -1;
            }
            s = s.substr(1);
        }
        index = 0;
        long long result = 0;
        while (index < s.length() && s[index] >= '0' && s[index] <= '9')
        {
            result = result * 10 + (s[index] - '0');
            long long tempResult = result * temp;
            if (tempResult <= -2147483648)
            {
                return -2147483648;
            }
            else if (tempResult >= 2147483647)
            {
                return 2147483647;
            }
            ++index;
        }
        return static_cast<int>(result * temp);
    }
};
// @lc code=end

