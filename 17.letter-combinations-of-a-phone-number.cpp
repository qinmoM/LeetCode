/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        std::vector<std::string> hash = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        std::vector<std::string> temp;
        std::vector<std::string> result;
        for (char c : hash[digits[0] - '2'])
        {
            result.push_back(std::string(1, c));
        }
        for (int i = 1; i < digits.length(); ++i)
        {
            int index = digits[i] - '2';
            temp.clear();
            for (char c : hash[index])
            {
                for (string& s : result)
                {
                    temp.push_back(s + std::string(1, c));
                }
            }
            result.swap(temp);
        }
        return result;
    }
};
// @lc code=end

