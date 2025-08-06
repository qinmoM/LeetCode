/*
 * @lc app=leetcode id=860 lang=cpp
 *
 * [860] Lemonade Change
 */

// @lc code=start
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int>& bills)
    {
        vector<int> v(2, 0);
        for (int i : bills)
        {
            switch (i)
            {
            case 5:
                ++v[0];
                break;
            case 10:
                if (!v[0])
                {
                    return false;
                }
                --v[0];
                ++v[1];
                break;
            case 20:
                if (v[1])
                {
                    if (v[0])
                    {
                        --v[0];
                        --v[1];
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    v[0] -= 3;
                    if (v[0] < 0)
                    {
                        return false;
                    }
                }
                break;
            }
        }
        return true;
    }
};
// @lc code=end

