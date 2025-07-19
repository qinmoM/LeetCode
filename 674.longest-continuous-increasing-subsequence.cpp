/*
 * @lc app=leetcode id=674 lang=cpp
 *
 * [674] Longest Continuous Increasing Subsequence
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    int findLengthOfLCIS(vector<int>& nums)
    {
        int size = nums.size();
        int result = 1;
        int curr = 1;
        for (int i = 1; i < size; i++)
        {
            if (nums[i] > nums[i - 1])
            {
                curr++;
            }
            else
            {
                result = result > curr ? result : curr;
                curr = 1;
            }
        }
        result = result > curr? result : curr;
        return result;
    }
};
// @lc code=end

