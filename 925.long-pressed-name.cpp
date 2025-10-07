/*
 * @lc app=leetcode id=925 lang=cpp
 *
 * [925] Long Pressed Name
 */

// @lc code=start
class Solution
{
public:
    bool isLongPressedName(string name, string typed)
    {
        int indexN = 0;
        int indexT = 0;
        while (name.length() > indexN && typed.length() > indexT)
        {
            if (name[indexN] == typed[indexT])
            {
                ++indexN, ++indexT;
            }
            else
            {
                if (indexT)
                {
                    if (typed[indexT - 1] == typed[indexT])
                    {
                        indexT++;
                        continue;
                    }
                }
                return false;
            }
        }
        if (indexN != name.length())
        {
            return false;
        }
        indexN = indexT - 1;
        while (typed.length() > indexT)
        {
            if (typed[indexT++] != typed[indexN])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

