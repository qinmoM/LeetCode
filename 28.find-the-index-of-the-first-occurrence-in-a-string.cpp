/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int allN = needle.length();
        if (!allN)
        {
            return 0;
        }
        int allH = haystack.length();
        vector<int> next = strNext(needle);
        int i = 0, j = 0;
        while (i < allH && j < allN)
        {
            if (-1 == j || haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else
            {
                j = next[j];
            }
        }
        return (j == allN) ? i - j : -1;
        // int allN = needle.length();
        // int allH_N = haystack.length() - allN;
        // if (allH_N < 0)
        // {
        //     return -1;
        // }
        // for (int i = 0; i <= allH_N; i++)
        // {
        //     int temp = 0;
        //     for (int j = 0; j < allN; j++)
        //     {
        //         if (haystack[i + j] != needle[j])
        //         {
        //             break;
        //         }
        //         temp += 1;
        //     }
        //     if (temp == allN)
        //     {
        //         return i;
        //     }
        // }
        // return -1;
    }

    vector<int> strNext(string& s)
    {
        int j = 0, k = -1;
        vector<int> next(s.length());
        next[0] = k;
        while (j < s.length() - 1)
        {
            if (-1 == k || s[j] == s[k])
            {
                j++;
                k++;
                if (s[j] == s[k])
                {
                    next[j] = next[k];
                }
                else
                {
                    next[j] = k;
                }
            }
            else
            {
                k = next[k];
            }
        }
        return next;
    }
};
// @lc code=end

