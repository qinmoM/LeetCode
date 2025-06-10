/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start

#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int all = 0;
        for (int i = 0; i < s.length(); i++)
        {
            switch (s[i])
            {
            case 'I':
                switch (s[i + 1])
                {
                case 'V':
                    i++;
                    all += 4;
                    break;
                case 'X':
                    i++;
                    all += 9;
                    break;
                default:
                    all += 1;
                    break;
                }
                break;
            case 'V':
                all += 5;
                break;
            case 'X':
                switch (s[i + 1])
                {
                case 'L':
                    i++;
                    all += 40;
                    break;
                case 'C':
                    i++;
                    all += 90;
                    break;
                default:
                    all += 10;
                    break;
                }
                break;
            case 'L':
                all += 50;
                break;
            case 'C':
                switch (s[i + 1])
                {
                case 'D':
                    i++;
                    all += 400;
                    break;
                case 'M':
                    i++;
                    all += 900;
                    break;
                default:
                    all += 100;
                    break;
                }
                break;
            case 'D':
                all += 500;
                break;
            case 'M':
                all += 1000;
                break;
            default:
                break;
            }
        }
        return all;
    }
};
// @lc code=end

