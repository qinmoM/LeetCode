/*
 * @lc app=leetcode id=1005 lang=cpp
 *
 * [1005] Maximize Sum Of Array After K Negations
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int largestSumAfterKNegations(vector<int>& nums, int k)
    {
        std::priority_queue<int, std::vector<int>, Comp> priority(nums.begin(), nums.end());
        while (priority.top() < 0 && k--)
        {
            int temp = -priority.top();
            priority.pop();
            priority.push(temp);
        }
        if (k >= 0 && k % 2)
        {
            int temp = -priority.top();
            priority.pop();
            priority.push(temp);
        }
        int result = 0;
        while (!priority.empty())
        {
            result += priority.top();
            priority.pop();
        }
        return result;
    }

private:
    struct Comp
    {
        bool operator()(const int& a, const int& b) const
        {
            return a > b;
        }
    };

};
// @lc code=end

