/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 */

// @lc code=start
#include <string>

using std::string;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        if (k == num.size())
        {
            return "0";
        }
        while (k)
        {
            int temp = 0;
            while (temp < num.size() && '0' == num[temp]) ++temp;
            num = num.substr(temp, num.size() - temp);
            int i = 1;
            if (i >= num.size())
            {
                return "0";
            }
            while (i < num.size() && num[i - 1] <= num[i]) ++i;
            if (i == num.size())
            {
                std::string t = num.substr(0, num.size() - k);
                return "" == t ? "0" : t;
            }
            num = num.substr(0, i - 1) + num.substr(i, num.size() - i);
            --k;
        }
        k = 0;
        while (k < num.size() && '0' == num[k]) ++k;
        return k == num.size() ? "0" : num.substr(k, num.size() - k);

        // if (k == num.size())
        // {
        //     return "0";
        // }
        // int tempK = k;
        // while (tempK--)
        // {
        //     int indexMax = 0;
        //     int i = 0;
        //     int temp = k;
        //     while (i < num.size() && temp--)
        //     {
        //         if (num[indexMax] < num[i])
        //         {
        //             indexMax = i;
        //         }
        //         while (0 == i || (i < num.size() && num[i] == num[i + 1])) ++i;
        //     }
        //     num = num.substr(0 , indexMax) + num.substr(indexMax + 1, num.size() - 1 - indexMax);
        // }
        // tempK = 0;
        // while (tempK < num.size() && '0' == num[tempK]) ++tempK;
        // return tempK == num.size() ? "0" : num.substr(tempK, num.size() - tempK);
    }
};
// @lc code=end

