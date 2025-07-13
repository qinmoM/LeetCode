/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
#include <stack>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int evalRPN(vector<string>& tokens)
    {
        int size = tokens.size();
        stack<int> transfer;
        int temp = 0;
        for (string& strTemp : tokens)
        {
            if ("+" == strTemp || "-" == strTemp ||
                "*" == strTemp || "/" == strTemp)
            {
                temp = transfer.top();
                transfer.pop();
                temp = calculate(transfer.top(), temp, strTemp);
                transfer.pop();
                transfer.push(temp);
            }
            else
            {
                transfer.push(stoi(strTemp));
            }
        }
        return transfer.top();
    }

    int calculate(const int left, const int right, const string& symbol)
    {
        if ("+" == symbol)
        {
            return left + right;
        }
        if ("-" == symbol)
        {
            return left - right;
        }
        if ("*" == symbol)
        {
            return left * right;
        }
        if ("/" == symbol)
        {
            return left / right;
        }
        throw "SB";
    }
};
// @lc code=end

