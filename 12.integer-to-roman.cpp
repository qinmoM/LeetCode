/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start

#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        int nums[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        char* symbols[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
        int temp = 0;
        for (int i = 0; i < 13; i++)
        {
            temp = nums[i];
            while (num >= temp)
            {
                num -= temp;
                result += symbols[i];
            }
        }
        return result;
        // string result = "";
        // int temp = 0;
        // while (num / 1000)
        // {
        //     num -= 1000;
        //     result += "M";
        // }
        // while (temp = num / 100)
        // {
        //     if (9 == temp)
        //     {
        //         num -= 900;
        //         result += "CM";
        //         break;
        //     }
        //     else if (5 <= temp)
        //     {
        //         num -= 500;
        //         result += "D";
                
        //     }
        //     else if (4 == temp)
        //     {
        //         num -= 400;
        //         result += "CD";
        //     }
        //     else
        //     {
        //         num -= 100;
        //         result += "C";
        //     }
        // }
        // while (temp = num / 10)
        // {
        //     if (9 == temp)
        //     {
        //         num -= 90;
        //         result += "XC";
        //         break;
        //     }
        //     else if (5 <= temp)
        //     {
        //         num -= 50;
        //         result += "L";
                
        //     }
        //     else if (4 == temp)
        //     {
        //         num -= 40;
        //         result += "XL";
        //     }
        //     else
        //     {
        //         num -= 10;
        //         result += "X";
        //     }
        // }
        // while (num)
        // {
        //     if (9 == num)
        //     {
        //         num -= 9;
        //         result += "IX";
        //     }
        //     else if (5 <= num)
        //     {
        //         num -= 5;
        //         result += "V";
        //     }
        //     else if (4 == num)
        //     {
        //         num -= 4;
        //         result += "IV";
        //     }
        //     else
        //     {
        //         num -= 1;
        //         result += "I";
        //     }
        // }
        // return result;
    }
};
// @lc code=end

