/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 */

// @lc code=start
#include <string>

using namespace std;

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int last = 0;
        int num1Index = num1.size() - 1;
        int num2Index = num2.size() - 1;
        std::string result;
        while (num1Index >= 0 || num2Index >= 0 || last / 10)
        {
            int temp = (num1Index >= 0 ? num1[num1Index--] - '0' : 0) + (num2Index < 0 ? 0 : num2[num2Index--] - '0');
            result = std::to_string((temp + last / 10) % 10) + result;
            last = temp + last / 10;
        }
        return result;
    }
};
// @lc code=end

