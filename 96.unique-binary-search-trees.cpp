/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution
{
public:
    int numTrees(int n)
    {
        return num(1, n);
    }

    int num(int left, int right)
    {
        if (left >= right) return 1;
        int count = 0;
        for (int i = left; i <= right; ++i)
        {
            count += num(left, i - 1) * num(i + 1, right);
        }
        return count;
    }
};
// @lc code=end

