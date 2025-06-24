/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int result = 0;
        for (int temp : nums)
        {
            result ^= temp;
        }
        return result;
    }
};
// @lc code=end

