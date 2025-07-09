/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int size = nums.size();
        int curr = 0, result = 0;
        for (int i = 0; i < size; i++)
        {
            if (0 == nums[i])
            {
                if (curr > result)
                {
                    result = curr;
                }
                curr = 0;
            }
            else
            {
                curr++;
            }
        }
        if (curr > result)
        {
            return curr;
        }
        else
        {
            return result;
        }
    }
};
// @lc code=end

