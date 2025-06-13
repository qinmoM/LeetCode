/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start

#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int allN = needle.length();
        int allH_N = haystack.length() - allN;
        if (allH_N < 0)
        {
            return -1;
        }
        for (int i = 0; i <= allH_N; i++)
        {
            int temp = 0;
            for (int j = 0; j < allN; j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    break;
                }
                temp += 1;
            }
            if (temp == allN)
            {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

