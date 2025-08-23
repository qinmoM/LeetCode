/*
 * @lc app=leetcode id=941 lang=cpp
 *
 * [941] Valid Mountain Array
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    bool validMountainArray(vector<int>& arr)
    {
        if (arr.size() < 3)
        {
            return false;
        }

        bool isAscend = true;
        int last = arr[0];
        for (int i = 1; i < arr.size(); ++i)
        {
            if (isAscend)
            {
                if (last == arr[i])
                {
                    return false;
                }
                else if (last > arr[i])
                {
                    if (i == 1)
                    {
                        return false;
                    }
                    isAscend = false;
                }
            }
            else
            {
                if (last == arr[i] || last < arr[i])
                {
                    return false;
                }
            }

            last = arr[i];
        }
        return !isAscend;
    }
};
// @lc code=end

