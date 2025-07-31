/*
 * @lc app=leetcode id=1013 lang=cpp
 *
 * [1013] Partition Array Into Three Parts With Equal Sum
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    bool canThreePartsEqualSum(vector<int>& arr)
    {
        int size = arr.size();
        int total = 0;
        int temp = 0;
        int count = 0;

        for (int i : arr)
        {
            total += i;
        }

        if (total % 3 != 0)
        {
            return false;
        }
        total /= 3;

        for (int i = 0; i < size; ++i)
        {
            temp += arr[i];
            if (temp == total)
            {
                ++count;
                if (2 == count && i != size - 1)
                {
                    return true;
                }
                temp = 0;
            }
        }
        return false;
        // int size = arr.size();
        // int left = 0;
        // int mid = 0;
        // int all = 0;
        // 
        // for (int i : arr)
        // {
        //     all += i;
        // }
        // 
        // for (int i = 0; i < size - 2; ++i)
        // {
        //     left += arr[i];
        //     for (int j = i + 1; j < size - 1; ++j)
        //     {
        //         mid += arr[j];
        //         if (mid != left)
        //         {
        //             continue;
        //         }
        //         else
        //         {
        //             if (all - left - mid == left)
        //             {
        //                 return true;
        //             }
        //         }
        //     }
        //     mid = 0;
        // }
        // return false;
    }
};
// @lc code=end

