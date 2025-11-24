/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start
#include <string>

using std::string;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0") return "0";
        std::string result = "0";
        for (int i = 0; i < num2.size(); ++i)
        {
            std::string s1 = "0";
            for (int j = 0; j < num1.size(); ++j)
            {
                int index1 = num1.size() - j - 1;
                int index2 = num2.size() - i - 1;
                std::string temp = std::to_string((num2[index2] - '0') * (num1[index1] - '0')) + std::string(i + j, '0');
                s1 = calPlus(s1, temp);
            }
            result = calPlus(result, s1);
        }
        return result;
    }

    std::string calPlus(const std::string& a, const std::string& b)
    {
        bool carry = false;
        int size_max = a.size() > b.size() ? a.size() : b.size();
        std::string result;
        for (int i = 0; i < size_max; ++i)
        {
            int aIndex = a.size() - i - 1;
            int bIndex = b.size() - i - 1;
            int temp = (carry ? 1 : 0) + (aIndex < 0 ? 0 : a[aIndex] - '0') + (bIndex < 0 ? 0 : b[bIndex] - '0');
            carry = temp / 10;
            temp %= 10;
            result = std::to_string(temp) + result;
        }
        if (carry) result = "1" + result;
        return result;
    }

};
// @lc code=end

