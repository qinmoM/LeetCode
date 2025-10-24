/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
#include <vector>

using std::vector;

class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int amount = 0;
        int index  = -1;
        for (int i = 0; i < gas.size(); ++i)
        {
            int temp = gas[i] - cost[i];
            if (amount + temp < 0)
            {
                amount = 0;
                index = -1;
                continue;
            }
            if (-1 == index)
            {
                index = i;
            }
            amount += temp;
        }
        if (-1 == index)
        {
            return -1;
        }
        for (int i = 0; i < index; ++i)
        {
            if ((amount += (gas[i] - cost[i])) < 0)
            {
                return -1;
            }
        }
        return index;

        // int amount = 0;
        // int index = -1;
        // for (int i = 0; i < gas.size(); )
        // {
        //     int temp = gas[i] - cost[i];
        //     if (amount + temp >= 0)
        //     {
        //         amount += temp;
        //         ++i;
        //         continue;
        //     }
        //     amount = 0;
        //     while (++i < gas.size())
        //     {
        //         if (gas[i] - cost[i] >= 0)
        //         {
        //             index = i;
        //             break;
        //         }
        //     }
        // }
        // return index;
    }
};
// @lc code=end

