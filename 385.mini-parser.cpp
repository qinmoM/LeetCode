/*
 * @lc app=leetcode id=385 lang=cpp
 *
 * [385] Mini Parser
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
#include <vector>
#include <string>

using std::string;
using std::vector;

// class NestedInteger
// {
// public:
//     // Constructor initializes an empty nested list.
//     NestedInteger();
//     // Constructor initializes a single integer.
//     NestedInteger(int value);
//     // Return true if this NestedInteger holds a single integer, rather than a nested list.
//     bool isInteger() const;
//     // Return the single integer that this NestedInteger holds, if it holds a single integer
//     // The result is undefined if this NestedInteger holds a nested list
//     int getInteger() const;
//     // Set this NestedInteger to hold a single integer.
//     void setInteger(int value);
//     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
//     void add(const NestedInteger &ni);
//     // Return the nested list that this NestedInteger holds, if it holds a nested list
//     // The result is undefined if this NestedInteger holds a single integer
//     const vector<NestedInteger> &getList() const;
// };

class Solution
{
public:
    NestedInteger deserialize(string s)
    {
        if ('[' != s[0]) return NestedInteger(std::stoi(s));

        bool negative = false;
        int temp = 0;
        char last = '\0';
        std::vector<NestedInteger> stack;

        for (char c : s)
        {
            if ('-' == c)
            {
                negative = true;
            }
            else if ('[' == c)
            {
                stack.push_back(NestedInteger());
            }
            else if (']' == c || ',' == c)
            {
                if (last >= '0' && last <= '9')
                    stack.back().add(NestedInteger(temp * (negative ? -1 : 1)));

                temp = 0;
                negative = false;

                if (']' == c && stack.size() > 1)
                {
                    NestedInteger t = stack.back();
                    stack.pop_back();
                    stack.back().add(t);
                }
            }
            else
            {
                temp = temp * 10 + c - '0';
            }
            last = c;
        }

        return stack.back();
    }
};
// @lc code=end

