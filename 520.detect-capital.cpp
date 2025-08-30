/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 */

// @lc code=start
#include <string>

using namespace std;

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        if (word.size() < 2)
        {
            return true;
        }
        bool first_upper = word[0] <= 'Z';
        bool other_upper = word[1] <= 'Z';
        if (!first_upper && other_upper)
        {
            return false;
        }
        for (int i = 2; i < word.size(); ++i)
        {
            if (other_upper ^ (word[i] <= 'Z'))
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

