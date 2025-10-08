/*
 * @lc app=leetcode id=1021 lang=cpp
 *
 * [1021] Remove Outermost Parentheses
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        int count = 0;
        std::string result;
        for (char c : s)
        {
            if ('(' == c)
            {
                if (count)
                {
                    result += "(";
                }
                count += 1;
            }
            else if (')' == c)
            {
                count -= 1;
                if (count)
                {
                    result += ")";
                }
            }
        }
        return result;
    }
};
// @lc code=end

