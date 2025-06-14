/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.size() == 0)
        {
            return { 1 };
        }
        bool isCarry = 1;
        int all = digits.size();
        for (int i = 1; isCarry; i++)
        {
            isCarry = false;
            digits[all - i] += 1;
            if (digits[all - i] > 9)
            {
                digits[all - i] = 0;
                isCarry = true;
                if (digits.size() <= i)
                {
                    digits.push_back(0);
                    all = digits.size();
                    for (int j = all - 1; j > 0; j--)
                    {
                        digits[j] = digits[j - 1];
                    }
                }
            }
        }
        return digits;
    }
};
// @lc code=end

