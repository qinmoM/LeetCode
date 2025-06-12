/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start

#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int leftnum = 0;
        int length = s.length();
        if (1 >= length)
        {
            return false;
        }
        for (int i = 0; i < length; i++)
        {
            int tempnum = 0;
            char temp = s[i];
            if (1 == type(temp))
            {
                leftnum--;
                if (0 == i)
                {
                    return false;
                }
                for (int j = i - 1; j >= 0; j--)
                {
                    char tempC = s[j];
                    if (1 == type(tempC))
                    {
                        tempnum += 1;
                    }
                    if (-1 == type(tempC))
                    {
                        tempnum -= 1;
                        if (-1 == tempnum)
                        {
                            if (!isSame(temp, tempC))
                            {
                                return false;
                            }
                            break;
                        }
                    }
                    if (0 == j && tempnum > -1)
                    {
                        return false;
                    }
                }
            }
            else if (-1 == type(temp))
            {
                leftnum++;
            }
        }
        if (leftnum)
        {
            return false;
        }
        return true;
    }

    int type(char s)
    {
        switch (s)
        {
        case '(':
        case '[':
        case '{':
            return -1;
        case ')':
        case ']':
        case '}':
            return 1;
        default:
            return 0;
        }
    }

    bool isSame(char c1, char c2)// is right?->is same?
    {
        switch (c2)
        {
        case '[':
            if (']' == c1)
            {
                return true;
            }
            break;
        case '(':
            if (')' == c1)
            {
                return true;
            }
            break;
        case '{':
            if ('}' == c1)
            {
                return true;
            }
            break;
        default:
            break;
        }
        return false;
    }
};
// @lc code=end

