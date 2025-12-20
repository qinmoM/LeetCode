/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
#include <unordered_map>

class Solution
{
public:
    int numTrees(int n)
    {
        std::unordered_map<int, int> hash;
        return num(hash, 1, n);
    }

    int num(std::unordered_map<int, int>& hash, int left, int right)
    {
        if (left >= right) return 1;
        int count = 0;
        int temp = right - left;
        if (hash.find(temp) == hash.end())
        {
            for (int i = left; i <= right; ++i)
            {
                count += num(hash, left, i - 1) * num(hash, i + 1, right);
            }
            hash[temp] = count;
        }
        else count = hash[temp];
        return count;
    }
};
// @lc code=end

