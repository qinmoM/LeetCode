/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 */

// @lc code=start
#include <string>
#include <numeric>

using namespace std;

class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        if (str1 + str2 != str2 + str1)
        {
            return "";
        }

        return str1.substr(0, gcd(str1.length(), str2.length()));

        // if (str1 == str2)
        // {
        //     return str1;
        // }
        // if (str1.length() < str2.length())
        // {
        //     swap(str1, str2);
        // }

        // int len = str1.length() - str2.length();
        // for (int i = len; i > 0; --i)
        // {
        //     if (len % i)
        //     {
        //         continue;
        //     }
        //     string temp = str2.substr(0, i);
        //     while (temp.length() < str1.length())
        //     {
        //         temp += str2.substr(0, i);
        //     }
        //     if (temp == str1)
        //     {
        //         return str2.substr(0, i);
        //     }
        // }

        // return "";
    }
};
// @lc code=end

