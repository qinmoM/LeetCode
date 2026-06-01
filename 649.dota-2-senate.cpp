/*
 * @lc app=leetcode id=649 lang=cpp
 *
 * [649] Dota2 Senate
 */

// @lc code=start
#include <string>

using std::string;

class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        int rSize = 0;
        int dSize = 0;
        int res = 0;

        for (char c : senate)
        {
            if ('R' == c)
                ++rSize;
            else
                ++dSize;
        }

        while (rSize && dSize)
        {
            std::string temp;
            for (char c : senate)
            {
                if ('R' == c)
                {
                    if (res < 0)
                    {
                        ++res;
                        --rSize;
                    }
                    else
                    {
                        temp.push_back('R');
                        ++res;
                    }
                }
                else
                {
                    if (res > 0)
                    {
                        --res;
                        --dSize;
                    }
                    else
                    {
                        temp.push_back('D');
                        --res;
                    }
                }
            }
            senate.swap(temp);
        }

        return rSize ? "Radiant" : "Dire" ;
    }
};
// @lc code=end

