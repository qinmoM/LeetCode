/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 */

// @lc code=start
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        char character = 0;
        for (char c : t)
        {
            character ^= c;
        }
        for (char c : s)
        {
            character ^= c;
        }
        return character;

        // std::unordered_map<char, int> hash;
        // for (char c : t)
        // {
        //     ++hash[c];
        // }
        // for (char c : s)
        // {
        //     --hash[c];
        // }
        // for (char c : t)
        // {
        //     if (1 == hash[c])
        //     {
        //         return c;
        //     }
        // }
        // throw -1;
    }
};
// @lc code=end

